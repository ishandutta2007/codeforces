//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 100050;
const int LOGN = 17;
int par[LOGN][MAXN];			// par[i][v]: (2^i)th ancestor of v
int level[MAXN], sub[MAXN];		// sub[v]: size of subtree whose root is v
int height[MAXN];
int ctPar[MAXN];				// ctPar[v]: parent of v in centroid tree
set<p32> adj[MAXN];
v32 cen_adj[MAXN];
int n, l, w;

// calculate level by dfs
void dfsLevel(int node, int pnode) {
	for(auto cnode : adj[node]) {
		if(cnode.fi != pnode) {
			par[0][cnode.fi] = node;
			level[cnode.fi] = level[node] + 1;
			height[cnode.fi] = height[node] + cnode.se;
			dfsLevel(cnode.fi, node);
		}
	}
}

void preprocess() {
	level[0] = 0;
	par[0][0] = 0;
	height[0] = 0;
	dfsLevel(0, -1);

	for(int i = 1; i < LOGN; i++) {
		for(int node = 0; node < n; node++) {
			par[i][node] = par[i-1][par[i-1][node]];
		}
	}
}

int lca(int u, int v) {
	if(level[u] > level[v]) swap(u, v);
	int d = level[v] - level[u];

	// make u, v same level
	for(int i = 0; i < LOGN; i++) {
		if(d & (1 << i)) {
			v = par[i][v];
		}
	}

	if(u == v) return u;

	// find LCA
	for(int i = LOGN - 1; i >= 0; i--) {
		if(par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

p32 dist(int u, int v) {
	int l = lca(u, v);
	int a1 = level[u] + level[v] - 2 * level[l];
	int a2 = height[u] + height[v] - 2 * height[l];
	return {a1, a2};
}


/* Centroid decomposition */
// Calculate size of subtrees by dfs
void dfsSubtree(int node, int pnode) {
	sub[node] = 1;
	for(auto cnode : adj[node]) {
		if(cnode.fi != pnode) {
			dfsSubtree(cnode.fi, node);
			sub[node] += sub[cnode.fi];
		}
	}
}

// find Centroid
int dfsCentroid(int node, int pnode, int size) {
	for(auto cnode : adj[node]) {
		if(cnode.fi != pnode && sub[cnode.fi] > size / 2)
			return dfsCentroid(cnode.fi, node, size);
	}
	return node;
}

// Centroid decomposition
void decompose(int node, int pCtr) {
	dfsSubtree(node, -1);
	int ctr = dfsCentroid(node, node, sub[node]);
	if(pCtr == -1)
		pCtr = ctr;	// root of centroid tree
	else
		cen_adj[pCtr].pb(ctr);
	ctPar[ctr] = pCtr;

	for(auto cnode : adj[ctr]) {
		auto it = adj[cnode.fi].lower_bound({ctr, -MOD});
		adj[cnode.fi].erase(it);
		decompose(cnode.fi, ctr);
	}
	adj[ctr].clear();
}

ll ans = 0;
vp32 fil;

void dfs_do(int node, int par){
	forstl(r, cen_adj[node]){
		dfs_do(r, par);
	}
	fil.pb(dist(node, par));
}

ll solve(){
	ll temp = 0;
	
	sort(all(fil));
	vp32 rev;
	forstl(r, fil) rev.pb(r);
	reverse(all(rev));

	int ptr = 0;
	ordered_set o_set;

	forstl(r, rev){
		while((ptr < fil.size()) && (fil[ptr].fi+r.fi<=l)){
			o_set.insert(fil[ptr].se);
			ptr++;
		}
		temp += o_set.order_of_key(w - r.se + 1);
		// cout << r << " " << ptr << " " << temp << " ok so far " << ln;
	}
	forstl(r, fil){
		if(2*r.fi <= l){
			if(2*r.se <= w){
				temp--;
			}
		}
	}
	// cout << "Final " << temp << ln;
	return temp/2;
}

void answer(int node){
	vp64 fin;
	fin.pb({0, 0});
	forstl(r, cen_adj[node]){
		fil.clear();
		dfs_do(r, node);
		forstl(k, fil) fin.pb(k);
		ans -= solve();
	}
	fil.clear();
	forstl(k, fin) fil.pb(k);
	ans += solve();
	forstl(r, cen_adj[node]){
		answer(r);
	}
}

int main(){
	fastio;

	cin >> n >> l >> w;
	forn(i,n-1){
		int p, w;
		cin >> p >> w;
		p--;
		adj[p].insert({i+1, w});
		adj[i+1].insert({p, w});
	}

	preprocess();
	decompose(0, -1);

	int st = 0;
	while(st != ctPar[st]) st = ctPar[st];

	answer(st);

	cout << ans << ln;

	return 0;
}