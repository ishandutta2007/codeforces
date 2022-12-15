//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
const int LIM=5e6+5,MOD=1e9+7;
const ld EPS = 1e-9;

#define int long long int

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll fastpow(ll a, ll p){
	if(p<0) return 0;
	if(p == 0) return 1;
	ll z = fastpow(a, p/2);
	z = (z * z) % MOD;
	if(p%2) z = (a * z) % MOD;
	return z;
}

ll fact[LIM];
ll ifact[LIM];
ll three_inv;

ll C(ll n, ll k){
	// if((n==k) && (n==0)) return 1;
	if(k>n) return 0;
	ll ans = 0;
	ans = (fact[n] * ifact[k]) % MOD;
	ans = ans%MOD;
	ans = (ans * ifact[n-k]) % MOD;
	return ans;
}

ll ans(int n, int k){

	if(k<0) return 0;
	if(n == 1){
		if(k==0){
			return 3;
		}
		else if(k==1){
			return 1;
		}
		return 0;
	}
	if(k == 0){
		return fastpow(3, n);
	}
	if(k == n){
		return fastpow(3, n-1);
	}

	ll sum = 0;

	forsn(i, 1, k+1){
		// number of segments

		ll add = 0;

		add = (C(n-k, i) * fastpow(3, n - k - i)) % MOD;
		ll a2 = (C(n-k, i-1) * fastpow(3, n - k - (i-1)))%MOD;
		add = (add + a2) % MOD;
		a2 = (C(k-1, i-1) * fastpow(three_inv, i))%MOD;
		add = (add * a2)%MOD;

		// cout << (add * fastpow(3, k)) % MOD << ln;

		sum = (sum + add) % MOD;
	}
	sum = (sum * fastpow(3, k)) % MOD;

	return sum;
}

signed main(){
	fastio;

	ll n, k;
	cin >> n >> k;

	fact[0] = 1;
	forsn(i,1,LIM){
		fact[i] = (fact[i-1] * i) % MOD;
	}
	ifact[LIM-1] = fastpow(fact[LIM-1], MOD-2);
	rforn(i, LIM-2){
		ifact[i] = (ifact[i+1] * (i+1)) % MOD;
	}

	// cout << (fact[5] * ifact[5]) % MOD << ln;

	// cout << ifact[2] << ln;
	three_inv = fastpow(3, MOD-2);
	cout << ans(n, k) << ln;

	// pow2[0] = 1;
	// forsn(i,1,LIM){
	// 	pow2[i] = (pow2[i-1]*2) % MOD;
	// }

	// cout << (ans(n, k, 0) + ans(n, k, 1)) % MOD << ln;

	return 0;
}