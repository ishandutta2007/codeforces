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

struct Line{

	mutable ll k,m,p;
	bool operator<(const Line& o) const{return k<o.k;}
	bool operator<(ll x) const{return p<x;}
};

struct LineContainer: multiset<Line,less<>>{
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b){
		return a/b - ((a^b)<0 && a%b);
	}
	bool isect(iterator x, iterator y){
		if(y == end()) {x->p = inf; return false;}
		if(x->k == y->k) x->p = x->m > y->m ? inf: -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m){
		auto z = insert({k,m,0}), y = z++, x = y;
		while(isect(y,z)) z = erase(z);
		if(x != begin() && isect(--x,y)) isect(x,y = erase(y));
		while((y = x) != begin() && (--x)->p >= y->p) isect(x,erase(y));
	}
	ll query(ll x){
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k*x+l.m;
	}
};

LineContainer lc[LIM];
int a[LIM], b[LIM];
v32 adj[LIM];
ll ans[LIM];
bool visited[LIM];

void dfs(int node){
	visited[node] = 1;
	forstl(r,adj[node]){
		if(visited[r]) continue;
		dfs(r);
		if(lc[r].size()>lc[node].size()) swap(lc[r],lc[node]);
		forstl(l,lc[r]) lc[node].add(l.k,l.m);
	}
	if(lc[node].size() == 0) ans[node] = 0;
	else ans[node] = -lc[node].query(a[node]);
	lc[node].add(-b[node],-ans[node]);
}

int main(){
	fastio;

	int n;
	cin>>n;
	forn(i,n) cin>>a[i];
	forn(i,n) cin>>b[i];
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	forn(i,n){
		cout<<ans[i]<<" ";
	}
	cout<<ln;

	return 0;
}