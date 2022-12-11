#include <bits/stdc++.h>
using namespace std;
#define Maxn 507
char s[Maxn][Maxn];
int n,m,x,y;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (s[i][j]=='*'&&s[i-1][j]=='*'&&s[i+1][j]=='*'&&s[i][j-1]=='*'&&s[i][j+1]=='*')
            {
                if (x==0&&y==0)
                {
                    x=i;
                    y=j;
                } else
                {
                    printf("NO\n");
                    return 0;
                }
            }
    if (x==0&&y==0)
    {
        printf("NO\n");
        return 0;
    }
    if (x==1||s[x-1][y]!='*')
    {
        printf("NO\n");
        return 0;
    }
    if (x==n||s[x+1][y]!='*')
    {
        printf("NO\n");
        return 0;
    }
    if (y==1||s[x][y-1]!='*')
    {
        printf("NO\n");
        return 0;
    }
    if (y==m||s[x][y+1]!='*')
    {
        printf("NO\n");
        return 0;
    }
    for (int i=x,j=y-1;j>=1&&(s[i][j]=='*');j--) s[i][j]='.';
    for (int i=x,j=y+1;j<=m&&(s[i][j]=='*');j++) s[i][j]='.';
    for (int i=x-1,j=y;i>=1&&(s[i][j]=='*');i--) s[i][j]='.';
    for (int i=x+1,j=y;i<=n&&(s[i][j]=='*');i++) s[i][j]='.';
    s[x][y]='.';
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (s[i][j]=='*')
            {
                printf("NO\n");
                return 0;
            }
    printf("YES\n");
    return 0;
}