#include <bits/stdc++.h>
#define y1 yy1
#define y2 yy2
using namespace std;
#define Maxn 107
#define Maxm 20007
int T,n,m;
char ch[Maxn][Maxn];
int x1[Maxm],y1[Maxm],x2[Maxm],y2[Maxm],x3[Maxm],y3[Maxm],cnt;
void modify(int x,int y)
{
    if (ch[x][y]=='1') ch[x][y]='0'; else ch[x][y]='1';
}
void solve()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",ch[i]+1);
    cnt=0;
    for (int i=n;i>2;i--)
        for (int j=1;j<=m;j++)
            if (ch[i][j]=='1')
            {
                ++cnt;
                x1[cnt]=i,y1[cnt]=j;
                x2[cnt]=i-1,y2[cnt]=j;
                x3[cnt]=i-1;
                if (j+1<=m) y3[cnt]=j+1; else y3[cnt]=j-1;
                modify(x1[cnt],y1[cnt]);
                modify(x2[cnt],y2[cnt]);
                modify(x3[cnt],y3[cnt]);
            }
    for (int j=m;j>2;j--)
        for (int i=1;i<=2;i++)
            if (ch[i][j]=='1')
            {
                ++cnt;
                x1[cnt]=i,y1[cnt]=j;
                x2[cnt]=i,y2[cnt]=j-1;
                x3[cnt]=3-i,y3[cnt]=j-1;
                modify(x1[cnt],y1[cnt]);
                modify(x2[cnt],y2[cnt]);
                modify(x3[cnt],y3[cnt]);
            }
    bool flag=false;
    for (int a=0;a<2&&(!flag);a++)
        for (int b=0;b<2&&(!flag);b++)
            for (int c=0;c<2&&(!flag);c++)
                for (int d=0;d<2&&(!flag);d++)
                {
                    if ((a+b+c)%2!=ch[1][1]-'0') continue;
                    if ((a+b+d)%2!=ch[1][2]-'0') continue;
                    if ((a+c+d)%2!=ch[2][1]-'0') continue;
                    if ((b+c+d)%2!=ch[2][2]-'0') continue;
                    if (a==1)
                    {
                        ++cnt;
                        x1[cnt]=1,y1[cnt]=1;
                        x2[cnt]=1,y2[cnt]=2;
                        x3[cnt]=2,y3[cnt]=1;
                    }
                    if (b==1)
                    {
                        ++cnt;
                        x1[cnt]=1,y1[cnt]=1;
                        x2[cnt]=1,y2[cnt]=2;
                        x3[cnt]=2,y3[cnt]=2;
                    }
                    if (c==1)
                    {
                        ++cnt;
                        x1[cnt]=1,y1[cnt]=1;
                        x2[cnt]=2,y2[cnt]=1;
                        x3[cnt]=2,y3[cnt]=2;
                    }
                    if (d==1)
                    {
                        ++cnt;
                        x1[cnt]=1,y1[cnt]=2;
                        x2[cnt]=2,y2[cnt]=1;
                        x3[cnt]=2,y3[cnt]=2;
                    }
                    flag=true;
                }
    printf("%d\n",cnt);
    for (int i=1;i<=cnt;i++)
        printf("%d %d %d %d %d %d\n",x1[i],y1[i],x2[i],y2[i],x3[i],y3[i]);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}