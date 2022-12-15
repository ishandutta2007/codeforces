//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long int
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
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int LIM=1e5+5,MOD=1e9+7;
const int LOGN=17;

int n, m;
v32 adj[LIM];
int ctPar[LIM];
vp32 act_adj[LIM];
v32 child_cen[LIM];
bool done[LIM];
int sub[LIM];
bool cent_done[LIM];

// Calculate size of subtrees by dfs-ing

void dfsSubtree(int node, int pnode){
	sub[node] = 1;
	forstl(r, adj[node]){
		if(r != pnode && cent_done[r] == 0){
			dfsSubtree(r, node);
			sub[node] += sub[r];
		}
	}
}

// find the centroid

int dfsCentroid(int node, int pnode, int size){
	forstl(r, adj[node]){
		if(cent_done[r] == 0 && r != pnode && sub[r] > size / 2)
			return dfsCentroid(r, node, size);
	}
	return node;
}

// actual decomposition

void decompose(int node, int pCtr){
	dfsSubtree(node, -1);
	int ctr = dfsCentroid(node, node, sub[node]);
	if(pCtr == -1){
		pCtr = ctr; // when pctr = ctr, root of tree
	}
	ctPar[ctr] = pCtr;
	if(pCtr != ctr){
		child_cen[pCtr].pb(ctr);
	}
	cent_done[ctr] = 1;
	forstl(r, adj[ctr]){
		if(cent_done[r]) continue;
		decompose(r, ctr);
	}
}

ll fastpow(ll a, ll p, ll m){
	if(p == 0) return 1;
	ll z = fastpow(a, p/2, m);
	z = (z*z)%m;
	if(p%2) z = (a*z)%m;
	return z;
}

int phi(int n){
	int result = n;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			while(n % i == 0) n /= i;
			result -= result / i;
		}
	}
	if(n > 1)
		result -= result / n;
	return result;
}

int phi_val;
int inv_10;

ll ans = 0;
map<int,ll> up;

void dfsGetUp(int node, int pnode, int add_up, int dep, bool sub){
	int new_depth = (dep * 10) % m;
	forstl(r, act_adj[node]){
		if(r.fi == pnode || done[r.fi]) continue;
		int to_add_up = (add_up + dep * r.se) % m;
		if(sub) up[to_add_up]--;
		else up[to_add_up]++;
		dfsGetUp(r.fi, node, to_add_up, new_depth, sub);
	}
}

void dfsSolveDown(int node, int pnode, int add_down, int len){
	forstl(r, act_adj[node]){
		if(r.fi == pnode || done[r.fi]) continue;
		int to_add_down = (add_down * 10 + r.se) % m;
		
		int val_to_reach = fastpow(inv_10, len, m);
		val_to_reach = (val_to_reach * to_add_down) % m;
		val_to_reach = -val_to_reach;
		val_to_reach += m;
		val_to_reach %= m;
		ans += up[val_to_reach];
		if(to_add_down == 0) ans += 1;

		dfsSolveDown(r.fi, node, to_add_down, len+1);
	}
}

void solve(int node){

	up.clear();

	dfsGetUp(node, -1, 0, 1, 0);
	forstl(r, act_adj[node]){
		if(done[r.fi]) continue;
		up[r.se % m]--;
		dfsGetUp(r.fi, node, r.se, 10, 1);
		int val_to_reach = ((-(inv_10 * r.se) % m) + m) % m;
		// cout<<val_to_reach<<" "<<up[val_to_reach % m]<<" okay, this happened "<<ln;
		// cout<<up<<ln;
		ans += up[val_to_reach];
		if(val_to_reach == 0) ans += 1;
		dfsSolveDown(r.fi, node, r.se, 2);
		// cout<<"now we have "<<ans<<ln;
		up[r.se % m]++;
		dfsGetUp(r.fi, node, r.se, 10, 0);
	}
	ans += up[0];
	// cout<<node<<" "<<ans<<" "<<up<<ln;
	done[node] = 1;
	forstl(r, child_cen[node]){
		solve(r);
	}
}


signed main(){
	fastio;

	cin>>n>>m;

	forn(i,n-1){
		int u, v, w;
		cin>>u>>v>>w;
		act_adj[u].pb(mp(v,w));
		act_adj[v].pb(mp(u,w));
		adj[u].pb(v);
		adj[v].pb(u);
	}

	decompose(0, -1);

	phi_val = phi(m);
	inv_10 = fastpow(10, phi_val-1, m);
	int root = -1;

	forn(i,n){
		if(i == ctPar[i]) root = i;
	}
	solve(root);
	cout<<ans<<ln;

	return 0;
}