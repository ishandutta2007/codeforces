#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int mod = 1e9+7;
ll dp[5005][5005],dp2[5005][5005],tot[5005],a[5005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) dp[i][0]=1,tot[i]=0;
    for(int j=1;j<=k;++j) {
        for(int i=1;i<=n;++i) {
            dp[i][j] = (dp[i+1][j-1] + dp[i-1][j-1]) % mod;
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=0;j<=k;++j) {
            dp2[i][j]=dp[i][j]*dp[i][k-j]%mod;
            (tot[i] += dp2[i][j]) %= mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;++i) ans+=a[i]*tot[i]%mod;
    ans%=mod;
    while(q--) {
        int x,y;
        cin>>x>>y;
        ans-=a[x]*tot[x]%mod;
        a[x]=y;
        ans+=a[x]*tot[x]%mod;
        ans%=mod;
        if(ans<0) ans+=mod;
        cout<<ans<<'\n';
    }
}