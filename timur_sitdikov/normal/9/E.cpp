#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char g[51][51];
int col[51], st[51], prev[51], n;

int dfs(int s, int cl)
{
    int i;
    col[s]=cl;
    for(i=1; i<=n; i++)
        if (g[s][i])
        {
            if (col[i] && prev[s]!=i) return 1;
            if (!col[i]) {prev[i]=s; if (dfs(i, cl)) return 1;}
        }
    return 0;
}

int main()
{   

    int i, j, stack[2][51], top=0, m, a, b, f=0, cl=1, cl2;
    scanf("%d %d", &n, &m);
    if (m>n) {printf("NO"); return 0;}
    if (n==1)
    {
        if (m==1) printf("YES\n0");
        else printf("YES\n1\n1 1");
        return 0;
    }
    if (n==2)
    {
        if (m==0) printf("YES\n2\n1 2\n1 2");
        else 
        {
            for(i=0; i<m; i++)
            {
                scanf("%d %d", &a, &b);
                if (a==b) {printf("NO"); return 0;}
            }
            if (m==1) printf("YES\n1\n1 2");
            else printf("YES\n0");          
        }
        return 0;
    }
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        if (a==b) {printf("NO"); return 0;}
        if (g[a][b]) {printf("NO"); return 0;}
        g[a][b]=g[b][a]=1; st[a]++; st[b]++;
        if (st[a]>2 || st[b]>2) {printf("NO"); return 0;}
    }
    for(i=1; i<=n; i++)
        if (!col[i])
        {
            if (dfs(i, cl))
                if (m<n || f) {printf("NO"); return 0;}
                else f=1;
            cl++;
        }
    for(i=1; i<=n; i++)
    {
        if (st[i]==0) 
        {
            for(j=i+1; ;j++)
            {
                if (st[j]!=2 && (cl>2 && col[j]!=col[i] || cl==2)) break;
            }
            stack[0][top]=i; stack[1][top]=j; top++;
            st[i]++; st[j]++;
            cl2=col[j];
            for(j=1; j<=n; j++) 
                if (col[j]==cl2) col[j]=col[i];
            cl--;
            /*for(j=n; ; j--)
            {
                if (st[j]!=2 && (cl>2 && col[j]!=col[i] || cl==2)) break;
            }
            stack[0][top]=i; stack[1][top]=j; top++;
            st[i]++; st[j]++;
            cl2=col[j];
            for(j=1; j<=n; j++) 
                if (col[j]==cl2) col[j]=col[i];
            cl--;*/
        }
        if (st[i]==1)
        {
            for(j=i+1; ;j++)
            {
                if (st[j]!=2 && (cl>2 && col[j]!=col[i] || cl==2)) break;
            }
            stack[0][top]=i; stack[1][top]=j; top++;
            st[i]++; st[j]++;
            cl2=col[j];
            for(j=1; j<=n; j++) 
                if (col[j]==cl2) col[j]=col[i];
            cl--;
        }
    }
    printf("YES\n%d\n", top);
    for(i=0; i<top; i++)
        printf("%d %d\n", stack[0][i], stack[1][i]);
}