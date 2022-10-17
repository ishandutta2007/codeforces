#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005],b[100005];
ll dp[100005][2];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    ii cin>>b[i];
    ii
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+b[i]);
    }
    ll ans=0;
    ii ans=max(ans,dp[i][0]),ans=max(ans,dp[i][1]);
    cout<<ans<<endl;
}