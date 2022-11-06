#include<stdio.h>
const int MAX = 200010;
int M[MAX], e[MAX], p[MAX], l[MAX];
int C[MAX][20];
int L[MAX][20];
int stk[MAX], top=0;
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++)scanf("%d%d", p+i, l+i);
    stk[++top] = n;
    p[0] = -10;
    e[n] = n;
    M[n] = p[n] + l[n];
    for(i=1; i<20; i++)
    {
        C[n][i] = 0;
        L[n][i] = n;
    }
    for(i=n-1; i>=1; i--)
    {
        int f=1, r=top+1, m;
        stk[top+1] = 0;
        while(f<r)
        {
            m = (f+r)/2;
            if(p[stk[m]] <= p[i] + l[i]) r = m;
            else f = m+1;
        }
        if(r == top+1)
        {
            stk[++top] = i;
            e[i] = i;
            M[i] = p[i] + l[i];
        }
        else
        {
            e[i] = e[stk[r]];
            M[i] = p[i] + l[i];
            if(M[i] < M[stk[r]]) M[i] = M[stk[r]];
            while(top!=0 && M[stk[top]] <= M[i]) top--;
            stk[++top] = i;
        }
        if(e[i] == n)
        {
            for(j=1; j<20; j++)
            {
                C[i][j] = 0;
                L[i][j] = n;
            }
        }
        else
        {
            C[i][1] = p[e[i]+1] - M[i];
            L[i][1] = e[i]+1;
            for(j=2; j<20; j++)
            {
                C[i][j] = C[i][j-1] + C[L[i][j-1]][j-1];
                L[i][j] = L[L[i][j-1]][j-1];
            }
        }
    }
    int q, x, y;
    scanf("%d", &q);
    for(i=1; i<=q; i++)
    {
        scanf("%d%d", &x, &y);
        int ans = 0;
        while(1)
        {
            if(e[x] >= y) break;
            for(j=1; j<20; j++) if(L[x][j] >= y) break;
            if(j==1)
            {
                ans += C[x][1];
                break;
            }
            else
            {
                ans += C[x][j-1];
                x = L[x][j-1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}