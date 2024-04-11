#include <stdio.h>

int n;
int c[2000];
int A[2000], B[2000], k=0;

void dfs (int a, int b)
{
        int t = c[a];
        for (int i=1; i<=n; i++)
                if (c[i] == t)
                        c[i] = c[b];
}

int main ()
{
        scanf ("%d", &n);
        for (int i=1; i<=n; i++)
                c[i] = i;
        
        int a,b;        
        for (int i=1; i<n; i++)
        {
                scanf ("%d%d", &a, &b);
                if (c[a] == c[b])
                {
                        A[k] = a;
                        B[k] = b;
                        k++;
                }
                else
                        dfs(a,b);
        }
        
        printf ("%d\n", k);
        for (int j=0; j<k; j++)
                for (int i=1; i<=n; i++)
                        if (c[i] != c[A[j]])
                        {
                                printf ("%d %d  %d %d\n", A[j], B[j], A[j], i);
                                dfs(A[j], i);
                                break;
                        }
        
        return 0;
}