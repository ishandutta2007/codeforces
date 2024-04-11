#include <bits/stdc++.h>
using namespace std;
int n;
int ans[107][10007];
void calc(int x,int y)
{
    memset(ans,0,sizeof(ans));
    for (int i=0;i<x;i++)
    {
        ans[i][i]='a'-'a';
        ans[(i+1)%x][i]='e'-'a';
        ans[(i+2)%x][i]='i'-'a';
        ans[(i+3)%x][i]='o'-'a';
        ans[(i+4)%x][i]='u'-'a';
    }
    for (int i=x;i<y;i++)
    {
        ans[0][i]='a'-'a';
        ans[1][i]='e'-'a';
        ans[2][i]='i'-'a';
        ans[3][i]='o'-'a';
        ans[4][i]='u'-'a';
    }
    for (int i=0;i<x;i++)
        for (int j=0;j<y;j++)
            printf("%c",ans[i][j]+'a');
    printf("\n");
}
int main()
{
    scanf("%d",&n);
    for (int i=5;i<=n;i++)
        if (n%i==0&&(n/i>=5))
        {
            calc(i,n/i);
            return 0;
        }
    printf("%d\n",-1);
    return 0;
}