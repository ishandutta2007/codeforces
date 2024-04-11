// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
#define double long double
using namespace std;


// namespace std {
 
// template<class Fun>
// class y_combinator_result {
// 	Fun fun_;
// public:
// 	template<class T>
// 	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
// 	template<class ...Args>
// 	decltype(auto) operator()(Args &&...args) {
// 		return fun_(std::ref(*this), std::forward<Args>(args)...);
// 	}
// };
 
// template<class Fun>
// decltype(auto) y_combinator(Fun &&fun) {
// 	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
// }
 
// } // namespace std
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1,1,-1};
int dy[]={1,0,-1,0,1,-1};
// const int mod=998244353;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=200007;
const int K=10;

mt19937 rng(1234);

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
 
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}
 
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		for(int i=k;i<2*k;++i) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	for(int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	for(int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) for(int j = 0; j < k; ++j) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	for (int i = 0; i < n; ++i) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

int n,m;
int f[N],rf[N];

int calc(int n,int m){
    vi L(n+1,0),R(n+1,0);
    rep(i,n+1) L[i]=modpow(i,n)*rf[i]%mod, R[i]=((i&1?mod-rf[i]:rf[i]))%mod;
    auto ret=conv(L,R);
    int ans=0;
    for (int i=0;i<=min(n,m);++i){
        ans=(ans+ret[i])%mod;
        // cerr<<n<<" "<<i<<" "<<ret[i]<<endl;
    }
    return ans;
}

map<int,int> res;
int cnt[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>m;
    if (m==1){
        cout<<1;
        return 0;
    }
    if (n==1){
        cout<<1;
        return 0;
    }
    f[0]=rf[0]=1;
    for (int i=1;i<N;++i) f[i]=f[i-1]*i%mod;
    rf[N-1]=modpow(f[N-1],mod-2);
    for (int i=N-1;i>0;--i) rf[i-1]=rf[i]*i%mod;
    for (int i=1;i<=n;++i){
        int ub=(n+i-1)/i;
        if (res.find(ub)==res.end()) res[ub]=calc(ub,m);
        cnt[i]=res[ub]-1;
        // cerr<<i<<" "<<cnt[i]<<endl;
    }
    for (int i=n;i>0;--i){
        for (int j=2;i*j<=n;++j) cnt[i]=(cnt[i]-cnt[i*j]+mod)%mod;
    }
    cout<<cnt[1];
    return 0;
}

/*
0 0 1 1 0 1 
0 0 1 0 1 0
1 1 0 1 0 0
1 0 1 0 0 0
0 1 0 0 0 0
1 0 0 0 0 0
*/