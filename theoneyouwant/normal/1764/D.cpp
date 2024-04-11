//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int
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
const int LIM=2e5+5;
const ld EPS = 1e-9;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, p;

ll fastpow(ll a, ll p, ll m){
	if(p == 0) return 1;
	ll z = fastpow(a, p/2, m);
	z = (z*z)%m;
	if(p%2) z = (a*z)%m;
	return z;
}

ll fact[LIM];
ll ifact[LIM];

void precomp(){
	fact[0] = 1;
	forsn(i,1,LIM) fact[i] = (fact[i-1]*i)%p;

	ifact[LIM-1] = fastpow(fact[LIM-1], p-2, p);
	rforn(i, LIM-2){
		ifact[i] = (ifact[i+1]*(i+1))%p;
	}
}

ll ncr(ll a, ll b){
	if(a<b) return 0;
	ll z = (fact[a] * ifact[b])%p;
	z = (z * ifact[a-b])%p;
	return z;
}

signed main(){
	fastio;

	cin >> n >> p;

	int mi = n/2+1;

	int l = 1;
	int ans = 0;

	precomp();

	for(int r = l + mi; r <= n; r++){
		int num = 0;
		for(int v = 1; v <= n; v++){
			if(max(v-l,r-v)<mi) num++;
		}
		int le = r-l-1;
		// cout << num << endl;
		for(int i = 0; i <= n-r; i++){
			// cout << n-r << " " << i << endl;
			ll pos = ncr(n-r, i);
			// cout << le << " " << pos << endl;
			pos = (pos * fact[i+le-1])%p;
			pos = (pos * num) % p;
			ans = (ans + pos)%p;
		}
	}

	if(n%2==0){
		ans = (ans + fact[n-2])%p;
	}


	ans = (ans * n) % p;
	if(ans<0) ans += p;

	cout << ans << ln;

	return 0;
}