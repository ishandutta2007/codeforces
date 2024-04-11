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
const int LIM=300000+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct BCC{
	int n;
	vector<vector<p32>> adj;
	vector<vector<int>> edge_num; // to convert from adj list to edge representation 
	int num_edges; // initially 0 edges
	vector<int> is_bridge;
	vector<bool> visited;
	vector<int> tin, low;
	int timer;
	int cmp_no;
	vector<vector<p32>> tree; // Final graph representation
	vector<vector<int>> components;
	vector<queue<int>> Q;

	BCC(int n){
		this->n = n;
		adj.assign(n, vector<p32>());
		edge_num.assign(n, vector<int>());
		num_edges = 0;
	}

	void add_edge(int a, int b, int arti){
		// add undirected edge a --- b
		adj[a].push_back(make_pair(b, arti));
		adj[b].push_back(make_pair(a, arti));
		edge_num[a].push_back(num_edges);
		edge_num[b].push_back(num_edges);
		num_edges++;
	}

	void dfs(int v, int p = -1){
		visited[v] = true;
		tin[v] = low[v] = timer++;
		for(int iter = 0; iter < adj[v].size(); iter++){
			int to = adj[v][iter].fi;
			if(to == p) continue; // parent of vertex
			if(visited[to]){
				low[v] = min(low[v], tin[to]);
			}
			else{
				dfs(to, v);
				low[v] = min(low[v], low[to]);
				if(low[to] > tin[v]){
					// mark this edge as bridge edge
					is_bridge[edge_num[v][iter]] = 1;
				}
			}
		}
	}

	void find_bridges(){
		timer = 0;
		visited.assign(n, 0);
		tin.assign(n, -1);
		low.assign(n, -1);
		is_bridge.assign(num_edges, 0);
		for(int i = 0; i < n; i++){
			if(!visited[i]){
				dfs(i);
			}
		}
	}

	void component_dfs(int v){
		int curr_cmp = cmp_no;
		Q[curr_cmp].push(v);
		visited[v] = 1;
		while(!Q[curr_cmp].empty()){
			int u = Q[curr_cmp].front();
			Q[curr_cmp].pop();
			components[curr_cmp].push_back(u);
			for(int i = 0; i < adj[u].size(); i++){
				int edge = edge_num[u][i];
				int nxt = adj[u][i].fi;
				int arti = adj[u][i].se;
				if(visited[nxt]) continue;
				if(is_bridge[edge]){
					cmp_no++;
					tree[curr_cmp].push_back(mp(cmp_no, arti));
					tree[cmp_no].push_back(mp(curr_cmp, arti));
					component_dfs(nxt);
				}
				else{
					Q[curr_cmp].push(nxt);
					visited[nxt] = 1;
				}
			}
		}
	}

	void find_bcc(){
		find_bridges();
		Q.assign(n, queue<int>());
		components.assign(n, vector<int>());
		tree.assign(n, vector<p32>());
		cmp_no = 0;
		visited.assign(n, 0);
		for(int i = 0; i < n; i++){
			if(!visited[i]){
				component_dfs(i);
				cmp_no++;
			}
		}
	}
} b(LIM);

vp32 adj[LIM];
int comp[LIM] = {0};
int pres[LIM] = {0};
int has[LIM] = {0};
int vis[LIM] = {0};

void dfs(int node){
	vis[node] = 1;
	if(pres[node]) has[node] = 1;
	forstl(r, b.tree[node]){
		if(vis[r.fi]) continue;
		has[r.fi] = has[node];
		if(r.se) has[r.fi] = 1;
		dfs(r.fi);
	}
}

int main(){
	fastio;

	int n, m;
	cin>>n>>m;

	forn(i,m){
		int u, v, c;
		cin>>u>>v>>c;
		u--; v--;
		adj[u].pb(mp(v, c));
		adj[v].pb(mp(u, c));
		b.add_edge(u, v, c);
	}

	int st, fin;
	cin>>st>>fin;
	st--; fin--;
	b.find_bcc();

	forn(i,b.components.size()){
		forstl(r,b.components[i]){
			// cout<<i<<" "<<r<<ln;
			comp[r] = i;
		}
	}

	st = comp[st];
	fin = comp[fin];

	forn(i,n){
		forstl(r, adj[i]){
			if(r.se == 1 && comp[r.fi] == comp[i]){
				pres[comp[i]] = 1;
			}
		}
	}
	dfs(st);
	if(has[fin]) cout<<"YES"<<ln;
	else cout<<"NO"<<ln;


	return 0;
}