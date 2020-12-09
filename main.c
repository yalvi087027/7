#include <stdio.h>
#include <stdlib.h>

int poisk(int* a, int r,int l, int b)
{
    if(r==l)
    {
        if(a[r]==b)
        {
            return r;
        }else
        {
            return -1;
        }
    }
    int m = (l+r)/2;
    if(a[m]==b)
    {
        return m;
    }
    if(a[m]>b)
    {
        return poisk(a,r,m,b);
    }else
    {
        return poisk(a,m+1,l,b);
    }

}
int* func(int *a, int n, int *b, int m)
{
    int* c = malloc((m+n)*sizeof(int));
    int l = 0, r = 0, k = 0;
    while(l < n && r < m)
    {
        if (a[l] < b[r])
        {
            c[k] = a[l];
            k+=1;
            l+=1;
        }
        else
        {
            c[k] = b[r];
            k+=1;
            r+=1;
        }
    }

    if(l < n)
    {
        while (l < n)
        {
            c[k] = a[l];
            k+=1;
            l+=1;
        }
    }
    if(r < m)
    {
        while (r < m)
        {
            c[k] = b[r];
            k+=1;
            r+=1;
        }
    }
    return c;
}

int main()
{
    int nomer;
    while(1)
    {
        printf("\nvvedite nomer zadachi:\n");
        scanf("%d", &nomer);
        if (nomer == 3)
        {
            int n;
            printf("vvedite kolichestvo elementov:\n");
            scanf("%d", &n);
            int a[n];
            for (int i = 0; i < n; i++)
            {
                printf("a[%d]=", i);
                scanf("%d", &a[i]);
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[i] == a[j])
                    {
                        for (int k = j + 1; k < n; k++)
                        {
                            a[k - 1] = a[k];
                        }
                        a[n - 1] = 0;
                        if(a[j]!=0)
                        {
                            j = j - 1;
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i)
                printf("%d ", a[i]);
        }
        if (nomer == 5)
        {
            int n;
            printf("vvedite kolichestvo elementov:\n");
            scanf("%d", &n);
            int a[n];
            for (int i = 0; i < n; i++)
            {
                printf("a[%d]=", i);
                scanf("%d", &a[i]);
            }

            printf("vvedite element dlya poiska:\n");
            int k;
            scanf("%d",&k);
            int indeks = poisk(a,0,n-1,k);
            if(indeks==-1)
            {
                printf("takogo elementa net");
            }else
            {
                printf("etot element imeet v massive nomer %d",indeks);
            }
            printf("\n");
        }
        if (nomer == 6)
        {
            int n;
            printf("vvedite kolichestvo elementov massiva 1:\n");
            scanf("%d", &n);
            int a[n];
            for (int i = 0; i < n; i++)
            {
                printf("a[%d]=", i);
                scanf("%d", &a[i]);
            }
            int m;
            printf("vvedite kolichestvo elementov massiva 1:\n");
            scanf("%d", &m);
            int b[m];
            for (int i = 0; i < m; i++)
            {
                printf("a[%d]=", i);
                scanf("%d", &b[i]);
            }
            int* c = func(a,n,b,m);
            for (int i = 0; i < n+m; ++i)
                printf("%d ", c[i]);
        }
    }
    return 0;
}
