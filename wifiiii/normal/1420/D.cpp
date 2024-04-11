#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 300005;
const int mod = 998244353;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
void init()
{
    f[0] = 1;
    for(int i=1;i<maxn;++i) f[i]=f[i-1]*i%mod;
    rf[maxn-1] = fpow(f[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k||k<0)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
int main() {
    init();
    int n,k;
    cin>>n>>k;
    vector<int> l(n),r(n),v;
    for(int i=0;i<n;++i) {
        cin>>l[i]>>r[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    for(int i=0;i<n;++i) {
        l[i]=lower_bound(all(v),l[i])-v.begin();
        r[i]=lower_bound(all(v),r[i])-v.begin();
    }
    vector<int> lx(v.size()),rx(v.size());
    for(int i=0;i<n;++i) lx[l[i]]++,rx[r[i]]++;
    ll ans=0,cur=0;
    for(int i=0;i<v.size();++i) {
        cur+=lx[i];
        while(rx[i]) {
            ans+=comb(cur-1,k-1);
            cur--;rx[i]--;
        }
    }
    ans%=mod;
    cout<<ans<<endl;
}