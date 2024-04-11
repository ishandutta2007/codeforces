
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int g[55][55],sum[55][55];
int dp[55][55][55][55];

int get(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
    int n;
    cin>>n;
    ii ji
    {
        char c;
        cin>>c;
        if(c=='#') g[i][j]=1;
    }
    ii ji sum[i][j]=sum[i-1][j]+sum[i][j-1]+g[i][j]-sum[i-1][j-1];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            for(int i2=i;i2>=1;--i2)
            {
                for(int j2=j;j2>=1;--j2)
                {
                    if(get(i2,j2,i,j) == 0) continue;
                    dp[i][j][i2][j2] = max(i-i2+1,j-j2+1);
                    for(int k=i;k>i2;--k)
                    {
                        dp[i][j][i2][j2] = min(dp[i][j][i2][j2],dp[i][j][k][j2]+dp[k-1][j][i2][j2]);
                    }
                    for(int k=j;k>j2;--k)
                    {
                        dp[i][j][i2][j2] = min(dp[i][j][i2][j2],dp[i][j][i2][k]+dp[i][k-1][i2][j2]);
                    }
                }
            }
        }
    cout<<dp[n][n][1][1]<<endl;
}