#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
struct V {
	vector<pii> outs; // (dest, edge index)
	int nins = 0;
};

vi euler_walk(vector<V>& nodes, int nedges, int src=0) {
	int c = 0;
	trav(n, nodes) if((n.nins)%2) c++;
	if (c) return {};
	vector<vector<pii>::iterator> its;
	trav(n, nodes)
		its.push_back(n.outs.begin());
	vector<bool> eu(nedges,0);
	vi ret, s = {src};
	while(!s.empty()) {
		int x = s.back();
		auto& it = its[x], end = nodes[x].outs.end();
		while(it != end && eu[it->second]) ++it;
		if(it == end) { 
			ret.push_back(x); s.pop_back(); }
		else { 
			s.push_back(it->first); eu[it->second] = true; 
		}
	}
	if(sz(ret) != nedges+1||ret.front()!=ret.back())
		ret.clear(); // No Eulerian cycles/paths.
	
	// else, non-cycle if ret.front() != ret.back()
	reverse(all(ret));
	return ret;
}
int a[500009],b[500009],n;
vector<V> g;
map<pii,vi> m;
bool fg[500009];
void solve(int k){
	g.clear();
	g.resize((1<<k));
	rep(i,n){
		g[a[i]].outs.pb(mp(b[i],i));
		g[b[i]].outs.pb(mp(a[i],i));
		g[a[i]].nins++;
		g[b[i]].nins++;
	}
	vi ans = euler_walk(g,n,a[0]);
	if(sz(ans)){
		cout<<k<<'\n';
		rep(i,n) m[mp(a[i],b[i])].pb(i),m[mp(b[i],a[i])].pb(i);
		vi fns;
		rep(i,sz(ans)-1){
			pii z = mp(ans[i],ans[i+1]);
			vi& cur=m[z];
			while(fg[cur.back()]) cur.pop_back();
			int ix = cur.back();
			fg[ix]=1;
			if(a[ix]==ans[i]) fns.pb(2*ix+1),fns.pb(2*ix+2);
			else fns.pb(2*ix+2),fns.pb(2*ix+1);
		}
		trav(i,fns) cout<<i<<' ';
		exit(0);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cin>>n;
	rep(i,n) cin>>a[i]>>b[i];
	repD(i,20,0){
		int x = (1<<i)-1;
		rep(i,n) a[i]&=x,b[i]&=x;
		solve(i);
	}
	return 0;
}