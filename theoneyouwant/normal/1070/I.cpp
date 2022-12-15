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

int main(){
	fastio;
	int tests;
	cin>>tests;
	
	while(tests--){
		int n,m,k; 
		cin>>n>>m>>k;
		vp32 edges;
		int degree[n+1] = {0};
		v32 adj[n+1];
		forn(i,m){
			int a,b; cin>>a>>b;
			adj[a].pb(i+1);
			adj[b].pb(i+1);
			degree[a]++; degree[b]++;
			edges.pb(mp(a,b));
		}
		queue<p32> q;
		bool p = 1;
		int totl = 0;
		forsn(i,1,n+1){
			if(degree[i]>2*k) p = 0;
			if(degree[i]>k){
				q.push(mp(i,2*(degree[i]-k)));
				totl += 2*(degree[i]-k);
			}
		}

		int assign[m+1] = {0};
		Hopcroft_Karp h(max(totl,m));
		int last = 1;
		map<int,int> leftnode;
		leftnode[0] = 0;
		while(!q.empty()){
			auto t = q.front();
			q.pop();
			forsn(i,last,last+t.se){
				forstl(r,adj[t.fi]){
					h.addEdge(i,r);
				}
				leftnode[i] = t.fi;
			}
			last = last+t.se;
		}
		h.max_matching();
		v32 matchededges[n+1];

		forsn(i,1,totl+1){
			if(h.matchL[i] == 0) p = 0;
		}
		forsn(i,1,m+1){
			matchededges[leftnode[h.matchR[i]]].pb(i);
		}
		int ind = 0;
		forn(i,n+1){
			int first = 0;
			forstl(r,matchededges[i]){
				if(first == 0){
					ind++;
				}
				assign[r] = ind;
				first = 1-first;
			}
		}

		if(p == 0){
			forn(i,m) cout<<0<<" ";
			cout<<ln;
			continue;
		}
		else{
			forsn(i,1,m+1) cout<<assign[i]<<" ";
			cout<<ln;
		}
	}

	return 0;
}