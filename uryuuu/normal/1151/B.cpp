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
#define ll long long
#define N 500005
#define M 25
#define mod 1000000007
int inf=0x3f3f3f3f;
using namespace std;
const int maxn=510;
bool vis[maxn][1025];
int a[maxn][maxn];
int ans[maxn];
bool f[maxn][2];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    }
    for(int step=0;step<10;step++)
    {
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=0;k<2;k++)
                    f[i][k]|=f[i-1][k^((a[i][j]>>step)&1)];
        if(f[n][1])
        {
            int now=1;
            for(int i=n;i>=1;--i)
            {
                for(int j=1;j<=m;j++)
                {
                    if(f[i-1][now^((a[i][j]>>step)&1)])
                    {
                        ans[i]=j;
                        now^=((a[i][j]>>step)&1);
                        break;
                    }
                }
            }
            cout<<"TAK"<<endl;
            for(int i=1;i<=n;i++)
            {
                cout<<ans[i]<<" ";
            }
            return 0;
        }
    }
    cout<<"NIE"<<endl;
    return 0;
}