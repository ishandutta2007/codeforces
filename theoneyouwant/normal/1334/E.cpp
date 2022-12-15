//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=998244353;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll fastpow(ll a, ll p){
	if(p == 0) return 1;
	ll z = fastpow(a,p/2);
	z = (z*z)%MOD;
	if(p%2)  z = (a*z)%MOD;
	return z;
}

int main(){
	fastio;

	ll d; cin>>d;

	v64 primes;

	forsn(i,2,sqrt(d)+1){
		if(d%i == 0){
			primes.pb(i);
			while(d%i == 0) d /= i;
		}
	}
	if(d>1) primes.pb(d);

	ll fact[LIM] = {0};
	ll invfact[LIM] = {0};

	fact[0] = 1;
	forsn(i,1,LIM) fact[i] = (fact[i-1]*i)%MOD;
	invfact[LIM-1] = fastpow(fact[LIM-1],MOD-2);
	rforn(i,LIM-2) invfact[i] = (invfact[i+1]*(i+1))%MOD;

	int q; cin>>q;

	forn(i,q){
		ll u,v;
		cin>>u>>v;

		ll g = __gcd(u,v);
		u /= g;
		v /= g;

		ll ways = 1;
		ll tot1 = 0;

		forstl(r,primes){
			int k = 0;
			while(u%r == 0){
				tot1++;
				k++;
				u /= r;
			}	
			ways *= invfact[k];
			ways %= MOD;
		}
		ways *= fact[tot1];
		ways %= MOD;

		tot1 = 0;
		forstl(r,primes){
			int k = 0;
			while(v%r == 0){
				tot1++;
				k++;
				v /= r;
			}
			ways *= invfact[k];
			ways %= MOD;
		}
		ways *= fact[tot1];
		ways %= MOD;
		cout<<ways<<ln;

	}

	return 0;
}