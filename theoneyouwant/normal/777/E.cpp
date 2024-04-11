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
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
	int n;
	ll t[4*LIM];
	SegTree(int n){
		this->n = n;
		forn(i,4*LIM) t[i] = 0;
	}
	void build(int a[], int v, int tl, int tr){
		if(tl == tr) t[v] = a[tl];
		else{
			int tm = (tl+tr)>>1;
			build(a,v*2,tl,tm);
			build(a,v*2+1,tm+1,tr);
		}
	}
	ll get(int v, int tl, int tr, int pos){
		if(tl == tr) return t[v];
		int tm = (tl+tr)>>1;
		if(pos <= tm){
			return max(t[v],get(v*2,tl,tm,pos));
		}
		else{
			return max(t[v],get(v*2+1,tm+1,tr,pos));
		}
	}
	void range_update(int v, int tl, int tr, int l, int r, ll val){
		if(l>r) return;
		if(l == tl && r == tr) t[v] = max(t[v],val);
		else{
			int tm = (tl+tr)>>1;
			range_update(v*2,tl,tm,l,min(r,tm),val);
			range_update(v*2+1,tm+1,tr,max(l,tm+1),r,val);
		}
	}
};

int main(){
	fastio;

	int n;
	cin>>n;

	ll ans = 0;
	vector<pair<p32,int>> p;
	v32 bsearchkaro;
	forn(i,n){
		int a,b,h;
		cin>>a>>b>>h;
		p.pb(mp(mp(b,a),h));
	}
	sort(p.begin(),p.end(),greater<pair<p32,int>>());
	rforn(i,n-1){
		bsearchkaro.pb(p[i].fi.fi);
	}
	SegTree s(n);
	forn(i,n){
		ll z = p[i].se+s.get(1,0,n-1,i);
		ans = max(ans,z);
		auto it = bsearchkaro.end()-1-upper_bound(bsearchkaro.begin(),bsearchkaro.end(),p[i].fi.se);
		s.range_update(1,0,n-1,0,it,z);
	}
	cout<<ans<<ln;


	return 0;
}