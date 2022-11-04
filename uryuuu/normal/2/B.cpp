#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;

const long long Mod=1e9+7;
int a[1005][1005],dp2[1005][1005],dp5[1005][1005],n5[1005][1005],n2[1005][1005];
int n;
char s[2200];
void solve5()
{
    int xx=n,yy=n;
    for(int i=0;i<2*(n-1);i++)
    {
        if(dp5[xx-1][yy]<dp5[xx][yy-1])
        {
            s[i]='D';
            xx--;
        }
        else
        {
            s[i]='R';
            yy--;
        }
    }
    for(int i=2*n-3;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<endl;
}

void solve2()
{
    int xx=n,yy=n;
    for(int i=0;i<2*(n-1);i++)
    {
        if(dp2[xx-1][yy]<dp2[xx][yy-1])
        {
            s[i]='D';
            xx--;
        }
        else
        {
            s[i]='R';
            yy--;
        }
    }
    for(int i=2*n-3;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<endl;
}
int main()
{
    sync
    cin>>n;
    int sx,sy,f=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                sx=i;
                sy=j;
                f=1;
                continue;
            }

            while(a[i][j]%5==0)
            {
                n5[i][j]++;
                a[i][j]/=5;
            }
            while(a[i][j]%2==0)
            {
                n2[i][j]++;
                a[i][j]/=2;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp2[i][0]=inf;
        dp2[0][i]=inf;
        dp5[i][0]=inf;
        dp5[0][i]=inf;
    }
    dp2[1][1]=n2[1][1];
    dp5[1][1]=n5[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1&&j==1)
                continue;
            dp2[i][j]=min(dp2[i][j-1],dp2[i-1][j])+n2[i][j];
            dp5[i][j]=min(dp5[i][j-1],dp5[i-1][j])+n5[i][j];
        }
    }
    if(dp2[n][n]&&dp5[n][n]&&f)
    {
        cout<<1<<endl;
        for(int i=1;i<sx;i++)
            cout<<'D';
        for(int i=1;i<sy;i++)
            cout<<'R';
        for(int i=sx;i<n;i++)
            cout<<'D';
        for(int i=sy;i<n;i++)
            cout<<'R';
        cout<<endl;
        return 0;
    }
    if(dp2[n][n]<dp5[n][n])
    {
        cout<<dp2[n][n]<<endl;
        solve2();
    }
    else
    {
        cout<<dp5[n][n]<<endl;
        solve5();
    }
    return 0;
}