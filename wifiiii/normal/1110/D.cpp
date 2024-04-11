#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[1000005],dp[1000005][4][4];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        a[tmp]++;
    }
    int ans = 0;
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<3;++j)
            for(int k=0;k<3;++k)
                for(int l=0;l<3;++l)
                    if(a[i]>=j+k+l)
                        dp[i][k][l]=max(dp[i][k][l],dp[i-1][j][k]+(a[i]-j-k-l)/3+l);
        ans = max(ans, dp[i][0][0]);
    }
    cout<<ans<<endl;
}