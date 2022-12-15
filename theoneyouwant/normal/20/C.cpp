//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
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
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const ll MOD = 1e9+7, LIM = 1e5+5;
const ld EPS = 1e-9;
const ll INF = 1e16;

int main(){
	fastio;

	int V,m;
	cin>>V>>m;
	int par[V] = {0};
	vp32 AdjList[V];
	forn(i,m){
		int a,b,w;
		cin>>a>>b>>w;
		a--;
		b--;
		AdjList[a].pb(mp(b,w));
		AdjList[b].pb(mp(a,w));
	}
	int s = 0;
	v64 dist(V, INF); dist[s] = 0;
	// INF = 1B to avoid overflow
	priority_queue< p32, vector<p32>, greater<p32> > pq; pq.push(p32(0, s));
	while (!pq.empty()) {
	// main loop
	p32 front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
	int d = front.first, u = front.second;
	if (d > dist[u]) continue;
	// this is a very important check
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
	p32 v = AdjList[u][j];
	// all outgoing edges from u
	if (dist[u] + v.second < dist[v.first]) {
		par[v.fi] = u;
	dist[v.first] = dist[u] + v.second;
	// relax operation
	pq.push(p32(dist[v.first], v.first));
	} } }

	//cout<<dist[V-1]<<ln;
	if(dist[V-1]<INF){
		v32 v;
		int k = V-1;
		while(k!=0){
			v.pb(k+1);
			k = par[k];
		}
		v.pb(1);
		reverse(v.begin(),v.end());
		forstl(r,v) cout<<r<<" ";
		cout<<ln;
	}
	else{
		cout<<-1<<ln;
	}
	// this variant can cause duplicate items in the priority queue
	return 0;
}