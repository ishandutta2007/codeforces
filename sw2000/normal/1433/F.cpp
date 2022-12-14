#include<bits/stdc++.h>
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
#define endl '\n'
using namespace std;
const int N = 1e4 + 10;
typedef long long ll;
typedef pair<int,ll>pii;
int n,m,k;
int b[100][100];
int dp[100][100];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n>>m>>k;
    memset(b,-0x3f,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        memset(dp,-0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int j=1;j<=m;j++)
        {
            int a;cin>>a;
            for(int x=m/2;x;x--)
            {
                for(int y=0;y<k;y++)
                {
                    dp[x][y]=max(dp[x][y],dp[x-1][((y-a)%k+k)%k]+a);
                }
            }
        }

        for(int y=0;y<k;y++)
        {
            for(int j=0;j<=m/2;j++)
            {
                b[i][y]=max(b[i][y],dp[j][y]);
            }
        }
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int x=0;x<k;x++)
            {
                dp[i][(j+x)%k]=max(dp[i][(j+x)%k],dp[i-1][j]+b[i][x]);
            }
        }
    }
    cout<<dp[n][0];
    return 0;
}