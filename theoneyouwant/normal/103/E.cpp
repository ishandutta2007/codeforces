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
const int INF = 1e9+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Max matching 
//1 indexed Hopcroft-Karp Matching in O(E sqrtV)
struct Hopcroft_Karp{
	static const int inf = 1e9;
	int n;
	vector<int> matchL, matchR, dist;
	vector<vector<int> > g;
	Hopcroft_Karp(int n):n(n),matchL(n+1),matchR(n+1),dist(n+1),g(n+1){}
	void addEdge(int u, int v){
		g[u].pb(v);}
	bool bfs(){
		queue<int> q;
		for(int u=1;u<=n;u++){
			if(!matchL[u]){
				dist[u]=0;
				q.push(u);
			}else dist[u]=inf;}
		dist[0]=inf;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(dist[matchR[v]] == inf){
					dist[matchR[v]] = dist[u] + 1;
					q.push(matchR[v]);}}}
		return (dist[0]!=inf);}
	bool dfs(int u){
		if(!u) return true;
		for(auto v:g[u]){
			if(dist[matchR[v]] == dist[u]+1 &&dfs(matchR[v])){
				matchL[u]=v;
				matchR[v]=u;
				return true;}}
		dist[u]=inf;
		return false;}
	int max_matching(){
		int matching=0;
		while(bfs()){
			for(int u=1;u<=n;u++){
				if(!matchL[u])
					if(dfs(u)) matching++;}}
		return matching;}};

//Push-Relabel Algorithm for Flows - Gap Heuristic, Complexity: O(V^3)
//To obtain the actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges
struct edge{
	int from, to, cap, flow, index;
	edge(int from, int to, int cap, int flow, int index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}};
struct PushRelabel{
	int n;
	vector<vector<edge> > g;
	vector<long long> excess;
	vector<int> height,active,count;
	queue<int> Q;
	PushRelabel(int n): n(n),g(n),excess(n),height(n),active(n),count(2*n) {}
	void addEdge(int from, int to, int cap){
		g[from].push_back(edge(from,to,cap,0,g[to].size()));
		if(from==to) g[from].back().index++;
		g[to].push_back(edge(to,from,0,0, g[from].size()-1));}
	void enqueue(int v){
		if(!active[v] && excess[v]>0){
			active[v]=true;
			Q.push(v);}}
	void push(edge &e){
		int amt=(int)min(excess[e.from],(long long)e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0) return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);}
	void relabel(int v){
		count[height[v]]--;
		int d=2*n;
		for(auto &it:g[v]){
			if(it.cap-it.flow>0) d=min(d, height[it.to]+1);}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);}
	void gap(int k){
		for(int v=0;v<n;v++){
			if(height[v]<k) continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);}}
	void discharge(int v){
		for(int i=0; excess[v]>0 && i<g[v].size(); i++) push(g[v][i]);
		if(excess[v]>0){
			if(count[height[v]]==1) gap(height[v]);
			else relabel(v);}}
	long long max_flow(int source, int dest){
		count[0] = n-1;
		count[n] = 1;
		height[source] = n;
		active[source] = active[dest] = 1;
		for(auto &it:g[source]){
			excess[source]+=it.cap;
			push(it);}
		while(!Q.empty()){
			int v=Q.front();
			Q.pop();
			active[v]=false;
			discharge(v);}
		long long max_flow=0;
		for(auto &e:g[source]) max_flow+=e.flow;
		return max_flow;}};



int main(){
	fastio;

	int n; cin>>n;
	Hopcroft_Karp h(n);
	int cost[n+1];
	vector<p32> edges;

	forn(i,n){
		int m; cin>>m;
		forn(j,m){
			int x; cin>>x;
			h.addEdge(i+1,x);
			edges.pb(mp(i+1,x));
		}
	}	
	forsn(i,1,n+1) cin>>cost[i];
	h.max_matching();
	v32 adj[n+1];
	v32 final[n+1];
	forstl(r,edges){
		if(h.matchL[r.fi] == r.se) continue;
		adj[r.fi].pb(h.matchR[r.se]);
	}
	PushRelabel p(2*n+2);
	ll ans = 0;
	forsn(i,1,n+1){
		if(cost[i]<0){
			ans += cost[i];
			p.addEdge(0,i,-cost[i]);
		}else{
			p.addEdge(i,n+1,cost[i]);
		}
	}
	forsn(i,1,n+1){
		forstl(r,adj[i]){
			p.addEdge(i,r,INF);
		}
	}
	ans+=p.max_flow(0,n+1);
	cout<<ans<<ln;
	return 0;
}