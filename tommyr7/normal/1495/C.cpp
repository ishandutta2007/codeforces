#include <bits/stdc++.h>
using namespace std;
int T,n,m;
#define Maxn 507
char s[Maxn][Maxn];
void solve()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    if (n==1)
    {
        for (int i=1;i<=m;i++)
            s[1][i]='X';
    }
    else if (m==1)
    {
        for (int i=1;i<=n;i++)
            s[i][1]='X';
    }
    else if (n<=2&&m<=2)
    {
        // do nothing
    }
    else
    {
        for (int i=1;i<=n;i+=3)
            for (int j=1;j<=m;j++)
                s[i][j]='X';
        for (int i=1;i<=n;i+=3)
        {
            if (i+3<=n)
            {
                int pos=-1;
                for (int j=1;j<=m;j++)
                    if (s[i+1][j]=='X'||s[i+2][j]=='X') pos=j;
                if (pos==-1) pos=1;
                s[i+1][pos]='X';
                s[i+2][pos]='X';
            }
            else if (i+2==n)
            {
                for (int j=1;j<=m;j++)
                    if (s[i+2][j]=='X') s[i+1][j]='X';
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            printf("%c",s[i][j]);
        printf("\n");
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}