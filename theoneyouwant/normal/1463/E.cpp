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
const int LIM=3e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p[LIM];
int after[LIM];
int go_back[LIM];
int visited[LIM];
int to_be_vis[LIM];
int chain_no[LIM];
int completed[LIM];
v32 adj[LIM];
int num = 0;

v32 v;
bool pos = 1;

void solve(int node){
	if(to_be_vis[node] != -1 && go_back[node] == -1) return;
	if(visited[node]) return;
	visited[node] = 1;
	// cout<<node+1<<" "<<chain_no[node]<<ln;
	if(after[node] == -1){
		int f = node;
		v32 n;
		while(f != -1){
			n.pb(f);
			completed[f] = 1;
			f = go_back[f];
		}
		reverse(n.begin(), n.end());
		forstl(r,n) v.pb(r);
		f = node;
		n.clear();
		while(f != -1){
			forstl(r,adj[f]){
				n.pb(r);
			}
			f = go_back[f];
		}
		forstl(r,n) solve(r);
	}	
	else{
		if(chain_no[node] == -1){
			chain_no[node] = num+1;
			num++;
		}
		int nxt_node = after[node];
		int par_nxt_node = p[nxt_node];
		chain_no[nxt_node] = chain_no[node];
		go_back[nxt_node] = node;
		if((par_nxt_node == -1) || (chain_no[par_nxt_node] == chain_no[node]) || (completed[par_nxt_node] == 1)) solve(nxt_node);
	}
	return;
}

int main(){
	fastio;

	int n, k;
	cin>>n>>k;

	forn(i,LIM){
		p[i] = -1;
		after[i] = -1;
		go_back[i] = -1;
		visited[i] = 0;
		to_be_vis[i] = -1;
		chain_no[i] = -1;
		completed[i] = -1;
	}

	forn(i,n){
		cin>>p[i];
		p[i]--;
		if(p[i]>=0) adj[p[i]].pb(i);
	}
	forn(i,k){
		int x, y;
		cin>>x>>y;
		x--; y--;
		after[x] = y;
		to_be_vis[y] = x;
	}

	forn(i,n){
		if(p[i] == -1) solve(i);
	}

	forn(i,n){
		if(!visited[i]) pos = 0;
	}
	if(v.size() != n) pos = 0;

	if(pos){
		forstl(r,v) cout<<r+1<<" ";
		cout<<ln;
	}
	else{
		cout<<0<<ln;
	}


	return 0;
}