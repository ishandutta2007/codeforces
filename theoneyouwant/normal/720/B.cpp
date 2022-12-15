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
const int LIM=20000+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vp32 adj[LIM];
int visited[LIM];
p32 par[LIM];
vector<int> cyc[LIM];
int num_cyc;
vector<bool> done[LIM];
vector<int> conv[LIM];

void dfs(int node, int p){
	visited[node] = 1;
	int cnt = -1;
	forstl(r, adj[node]){
		int nxt = r.fi;
		int col = r.se;
		cnt += 1;
		if(done[node][cnt]) continue;
		if(nxt == p) continue;
		if(visited[nxt]){
			cyc[num_cyc].pb(col);
			int last = node;
			done[node][cnt] = 1;
			int oth = conv[node][cnt];
			done[nxt][oth] = 1;
			while(last != nxt){
				oth = conv[par[last].fi][par[last].se];
				int lll = adj[par[last].fi][par[last].se].fi;
				done[lll][oth] = 1;
				done[par[last].fi][par[last].se] = 1;
				int add_col = adj[par[last].fi][par[last].se].se;
				cyc[num_cyc].pb(add_col);
				last = par[last].fi;
			}
			num_cyc++;
			continue;
		}
		par[nxt] = mp(node, cnt);
		dfs(nxt, node);
	}
}

struct FlowEdge {
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e9;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, int cap) {
        edges.push_back({v, u, cap});
        edges.push_back({u, v, 0});
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow() {
        int f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            // int pushed = dfs(s, flow_inf);
            // f += pushed;
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main(){
	fastio;

	int n, m;
	cin>>n>>m;

	// assert(n <= 10000);
	// assert(m <= 10000);

	forn(i,m){
		int u, v, c;
		cin>>u>>v>>c;
		u--; v--;
		conv[u].pb(adj[v].size());
		conv[v].pb(adj[u].size());
		adj[u].pb(mp(v, c));
		adj[v].pb(mp(u, c));
		done[u].pb(0);
		done[v].pb(0);
	}

	par[0] = mp(0, 0);
	dfs(0, -1);

	forn(i,n){
		forn(j,adj[i].size()){
			if(done[i][j]) continue;
			done[i][j] = 1;
			int nxt = adj[i][j].fi;
			int oth = conv[i][j];
			done[nxt][oth] = 1;
			cyc[num_cyc].pb(adj[i][j].se);
			num_cyc++;
		}
	}

	forn(i,m){
		assert(cyc[i].size() != 2);
	}

	int s = 0, t = 2*m+1;
	// int cap[2*m+2][2*m+2];
	map<int,int> cap[2*m+2];

	// forn(i,2*m+2) forn(j,2*m+2) cap[i][j] = 0;

	// cap from u to v

	forsn(i,1,m+1){
		cap[0][i] = 1;
	}
	forn(i,m){
		int z = cyc[i].size();
		if(z <= 2) cap[m+1+i][t] = z;
		else cap[m+1+i][t] = z-1;
	}
	forn(i,m){
		forstl(r,cyc[i]){
			cap[r][m+1+i]++;
		}
	}

	Dinic d(2*m+2, s, t);

	for(int i = 0; i < 2*m+2; i++){
		forstl(r, cap[i]){
			d.add_edge(i, r.fi, r.se);
		}
		// for(int j = i+1; j < 2*m+2; j++){
		// 	if(cap[i][j] == 0) continue;
		// 	d.add_edge(i, j, cap[i][j]);
		// }
	}

	cout<<d.flow()<<ln;

	return 0;
}