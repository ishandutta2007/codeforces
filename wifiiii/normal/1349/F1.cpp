#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

ll t[5005][5005];
const int mod = 998244353;
ll ans[5005];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
int main() {
    t[1][1]=1;
    for(int n=2;n<=5000;++n) {
        for(int k=1;k<=n;++k) {
            t[n][k] = (k * t[n-1][k] + (n-k+1) * t[n-1][k-1]) % mod;
        }
    }
    ll f=1;
    int N;
    cin>>N;
    for(int i=1;i<=N;++i) f=f*i%mod;
    for(int i=1;i<=N;++i) ans[i]=f;
    for(int i=2;i<=N;++i) {
        ll tmp=ans[i];ans[i]=0;
        ll tot=0;for(int j=1;j<=i;++j) tot+=t[i][j];tot%=mod;
        tmp=tmp*fpow(tot,mod-2)%mod;
        for(int j=1;j<=i;++j) ans[j]=(ans[j]+tmp*t[i][j]%mod)%mod;
    }
    for(int i=1;i<=N;++i) cout<<ans[i]<<" ";cout<<endl;
}