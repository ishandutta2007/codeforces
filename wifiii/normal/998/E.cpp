#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

const int mod = 998244353;
const int maxn = 2000005;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b) {
    if(b<0) a=fpow(a,mod-2)%mod,b=-b;
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
void init(int n) {
    f[0] = 1;
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    rf[n] = fpow(f[n],mod-2);
    for(int i=n-1;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k||k<0)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
ll solve(ll n) {
    ll ret=0;
    for(ll x=1;x<=n;++x) {
        ll a=comb(n,x)*fpow(3,n*n+1-x*n)%mod;
        ll k=fpow(-1,x),k2=fpow(-1,n);
        a=a*(k2*fpow(fpow(3,x-n)-1,n)-1)%mod;
        ret+=a*k%mod;
    }
    ret%=mod;if(ret<0) ret+=mod;
    ll tmp=0;
    for(int x=1;x<=n;++x) {
        int k=x%2?1:-1;
        ll p = n*n+x-x*n;
        tmp+=k*comb(n,x)*fpow(3,p)%mod;
    }
    ret=tmp*2-ret;
    ret%=mod;
    if(ret<0) ret+=mod;
    return ret;
}
int main() {
    int n;
    cin >> n;
    init(n);
    cout<<solve(n)<<endl;
}