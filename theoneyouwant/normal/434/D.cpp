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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
	Push Relabel O(n^3) implimentation using FIFO method to chose push vertex.
	This uses gapRelabel heuristic to fasten the process even further. If only 
	the maxFlow value is required then the algo can be stopped as soon as the
	gap relabel method is called. However, to get the actual flow values in the
	edges, we need to let the algo terminate itself.
	
	This implimentation assumes zero based vertex indexing. Edges to the graph 
	can be added using the addEdge method only. capacity for residual edges is
	set to be zero. To get the actual flow values iterate through the edges and
	check for flow for an edge with cap > 0.

	This implimentaion is superior over dinic's for graphs where graph is dense  
	locally at some places and mostly sparse. For randomly generated graphs, this
	implimentation gives results within seconds for n = 10000 nodes, m = 1000000 
	edges.

	Code Tested on : SPOJ FASTFLOW
	@author : triveni
*/

typedef int fType;

struct edge
{
	int from, to;
	fType cap, flow;
	edge(int from, int to, fType cap, fType flow = 0) : from(from), to(to), cap(cap), flow(flow) {}	
};

struct PushRelabel
{
	int N;
	vector<edge> edges;
	vector<vector<int> > G;
	vector<int> h, inQ, count;
	vector<fType> excess;
	queue<int> Q;
	PushRelabel(int N) : N(N), count(N<<1), G(N), h(N), inQ(N), excess(N) {}

	void addEdge(int from, int to, int cap) {
		G[from].push_back(edges.size());
		edges.push_back(edge(from, to, cap));
		G[to].push_back(edges.size());
		edges.push_back(edge(to, from, 0));
	}

	void enQueue(int u) {
		if(!inQ[u] && excess[u] > 0) Q.push(u), inQ[u] = true;
	}

	void Push(int edgeIdx) {
		edge & e = edges[edgeIdx];
		int toPush = min<fType>(e.cap - e.flow, excess[e.from]);
		if(toPush > 0 && h[e.from] > h[e.to]) {
			e.flow += toPush;
			excess[e.to] += toPush;
			excess[e.from] -= toPush;
			edges[edgeIdx^1].flow -= toPush;
			enQueue(e.to);
		}
	}

	void Relabel(int u) {
		count[h[u]] -= 1; h[u] = 2*N-2;
		for (int i = 0; i < G[u].size(); ++i) {
			edge & e = edges[G[u][i]];
			if(e.cap > e.flow) h[u] = min(h[u], h[e.to]);
		}
		count[++h[u]] += 1;
	}

	void gapRelabel(int height) {
		for (int u = 0; u < N; ++u) if(h[u] >= height && h[u] < N) {
			count[h[u]] -= 1;
			count[h[u] = N] += 1;
			enQueue(u);
		}
	}

	void Discharge(int u) {
		for (int i = 0; excess[u] > 0 && i < G[u].size(); ++i) {
			Push(G[u][i]);
		}
		if(excess[u] > 0) {
			// if(h[u] < N && count[h[u]] < 2) gapRelabel(h[u]);
			Relabel(u);
		}
		else if(!Q.empty()) { // dequeue
			Q.pop();
			inQ[u] = false;
		}
	}

	fType getFlow(int src, int snk) {
		h[src] = N; inQ[src] = inQ[snk] = true;
		count[0] = N - (count[N] = 1);
		for (int i = 0; i < G[src].size(); ++i) {
			excess[src] += edges[G[src][i]].cap;
			Push(G[src][i]);
		}
		while (!Q.empty()) {
			Discharge(Q.front());
		}
		return excess[snk];
	}
};

const int INF = 1e15;
const int MAX = 1e10;

signed main(){
	fastio;

	int n, m;
	cin>>n>>m;
	vector<tuple<int,int,int>> v, rest;
	int tot = 0;
	forn(i,n){
		int a, b, c;
		cin>>a>>b>>c;
		v.pb({a,b,c});
	}
	vp32 cons;
	forn(i,n){
		int l, r;
		cin>>l>>r;
		cons.pb({l,r});
		tot += r-l+2;
	}
	forn(i,m){
		int u, v, d;
		cin>>u>>v>>d;
		u--; v--;
		rest.pb({u, v, d});
	}
	int s = 0;
	int t = tot + 1;

	PushRelabel d(tot+2);
	int curr = 1;
	int st[n] = {0};

	forn(i,n){
		st[i] = curr;
		d.addEdge(s, curr, INF);
		int l = cons[i].fi, r = cons[i].se;
		forn(j,r-l+1){
			int x = j + l;
			int a, b, c;
			tie(a,b,c) = v[i];
			int val = a * x * x + b * x + c;
			assert(MAX - val >= 0);
			d.addEdge(curr, curr+1, MAX - val);
			curr += 1;
		}
		d.addEdge(curr, t, INF);
		curr += 1;
	}
	forn(i,m){
		// xu <= xv + d
		// add edge from xu to xv - d of cap INF
		int u, v, dd;
		tie(u,v,dd) = rest[i];
		swap(u,v);
		int lv = cons[v].fi, rv = cons[v].se;
		int lu = cons[u].fi, ru = cons[u].se;
		forn(j,rv-lv+2){
			int curr_val = lv-1+j;
			int give_val = curr_val - dd;
			int offset = give_val - lu + 1;
			if(offset < 0) continue;
			if(offset >= ru-lu+2) continue;
			d.addEdge(st[v]+j, st[u]+offset, INF);
		}
	}

	cout << n * MAX - d.getFlow(s, t) <<endl;

	return 0;
}