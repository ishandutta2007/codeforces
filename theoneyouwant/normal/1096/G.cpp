#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("-O2")
// #pragma GCC optimize ("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define forstl(i,v) for(auto &i:v)
#define forn(i,n) for(int i=0;i<n;++i)
#define forsn(i,s,n) for(int i=s;i<n;++i)
#define rforn(i,e) for(int i=e;i>=0;--i)
#define rforsn(i,s,e) for(int i=e;i>=s;--i)
#define bitcount(i) __builtin_popcount(i) //(add ll)
#define ln '\n'
#define dbg(x) cerr<<#x<<" "<<x<<ln;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef vector<int> v32;
typedef vector<p32> vp32;
typedef vector<v32> vv32;
typedef pair<ll,ll> p64;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef vector<ll> v64;
typedef complex<double> cd;
const ld PI = acos(-1);
const int MOD = 998244353, LIM= 2e5+5;
const ld EPS = 1e-9;


ll power(ll a, ll p){
    if(p==0) return 1;
    ll x = power(a,p/2);
    x = (x*x)%MOD;
    if(p%2==1) x = (x*a)%MOD;
    return x;
}

ll inverse(ll a, ll x){
    return power(a,MOD-2);
}

ll root_pw = 1LL<<23;
ll root = 15311432;
ll root_1 = inverse(root,MOD);
const int mod=MOD;  

void ntt(vector<ll> & a, bool invert) {
    int n = a.size();
    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? root_1 : root;
        for (ll i = len; i < root_pw; i <<= 1)
            wlen = (ll)(1LL * wlen * wlen % mod);

        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (ll)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (ll)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        ll n_1 = inverse(n, mod);
        for (ll & x : a)
            x = (ll)(1LL * x * n_1 % mod);
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = fa[i]*(ll)fb[i]%mod;
    ntt(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i]%mod;
    return result;
}

v64 power1(v64 &a, ll p){
    v64 res;
    res.pb(1);
    while(p){
        if(p&1) res=multiply(res,a);
        a=multiply(a,a);
        p/=2;
    }
    // if(p==1) return a;
    // v32 x=power1(a,p/2);
    // auto res=(multiply(x,x));
    // if(p%2==1) res = multiply(res,a);
    return res;
}
int main(){
    fastio;
    v64 v1;
    int n,k;
    cin>>n>>k;
    int done[10] = {0};
    forn(i,k){
        int x;
        cin>>x;
        done[x] = 1;
    }
    forn(i,10){
        if(done[i]) v1.pb(1);
        else v1.pb(0);
    }
    ll y1=1;
    while(y1<max(10,5*n)) y1<<=1;
    forsn(i,10,y1){
        v1.pb(0);
    }
    ntt(v1,false);
    forn(i,v1.size()){
        v1[i] = power(v1[i],n/2);
    }
    ntt(v1,true);
    ll ans=0;
    forstl(r,v1){
        ans+=r*r;
        ans%=MOD;
    }
    cout<<ans<<ln;
    return 0;
}