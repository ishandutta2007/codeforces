#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
ll mod = 998244352;
struct Matrix {
	typedef Matrix M;
	int N;
	vector<vector<ll>> d;
	Matrix(int N): N(N) {
		d.resize(N,vector<ll>(N,0));
	}
	M operator*(const M& m) const {
		M a(N);
		rep(i,N) rep(j,N){
			rep(k,N) a.d[i][j] += d[i][k]*m.d[k][j]%mod;
			a.d[i][j]%=mod;
		}
		return a;
	}
	vector<ll> operator*(const vector<ll>& vec) const {
		vector<ll> ret(N);
		rep(i,N) {
			rep(j,N) ret[i] += d[i][j] * vec[j]%mod;
			ret[i]%=mod;
		}
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a(N), b(*this);
		rep(i,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};
ll modpow(ll a, ll e) {
		if (e == 0) return 1;
			ll x = modpow(a * a % mod, e >> 1);
				return e & 1 ? x * a % mod : x;
}
vector<ll> divs;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	repA(i,1,100000){
		if(1ll*i*i>mod) break;
		if(mod%i==0) divs.pb(i),divs.pb(mod/i);
	}
	sort(all(divs));
	int n;cin>>n;
	Matrix M(n);
	rep(i,n) cin>>M.d[0][i];
	ll k,m;cin>>k>>m;
	repA(i,1,n-1) rep(j,n) if(i==j+1) M.d[i][j]=1; else M.d[i][j]=0;
	vector<ll> ans(n,0);
	ans[0]=1;
	ans = (M^(k-n))*ans;
	ll fns = ans[0]%mod;
	if(__gcd(fns,mod)==1){
		ll pp = modpow(fns,402653184-1);
		mod++;
		cout<<modpow(m,pp);
		exit(0);
	}
	mod++;
	trav(j,divs){
		if(modpow(m,j)==1) {
			ll s = (mod-1)/j;
			mod--;
			if(s%__gcd(fns,mod)!=0){
				cout<<-1;
			}
			else {
				ll g = __gcd(fns,mod);
				fns/=g;
				ll pow =(modpow(fns,402653184-1)*s/g)%mod;
				mod++;
				ll xx = modpow(3,s);
				ll gen = 1;
				int i=0;
				while(gen!=m) gen = gen*xx%mod,i++;
				cout<<(modpow(3,(pow*i)%(mod-1)));
			}
			return 0;
		}
	}
}