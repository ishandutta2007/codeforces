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

const int mod = 1e9+7;
ll dp[5005][5005];
inline void add(ll &a,ll b) {a=a+b>=mod?a+b-mod:a+b;}
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int main()
{
    int n,k;
    cin>>n>>k;
    dp[0][0]=1;
    for(int i=1;i<=k;++i)
        for(int j=i;j<=k;++j)
            dp[i][j] = (i*dp[i][j-1]%mod + (n-i+1)*dp[i-1][j-1]%mod)%mod ;
    ll ans=0;
    for(int i=1;i<=k;++i)
    {
        if(n-i<0) break;
        add(ans,dp[i][k]*fpow(2,n-i)%mod);
    }
    cout<<ans<<endl;
}