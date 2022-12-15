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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, s;

v32 adj[LIM];
int par[LIM];
int vis[LIM];
int ntime[LIM];
v32 cycle;
int c_time;
v32 r1, r2;

bool dfs(int node, int p){
	vis[node]=1;
	forstl(r, adj[node]){
		if(r==p) continue;
		if(r==s) continue;
		if(vis[r] && ntime[r]!=c_time){
			r1.pb(r);
			while(node!=-1){
				r1.pb(node);
				node=par[node];
			}
			while(r!=-1){
				r2.pb(r);
				r=par[r];
			}
			reverse(all(r1));
			reverse(all(r2));
			return 1;
		}
		if(vis[r]) continue;
		ntime[r] = c_time;
		par[r] = node;
		if(dfs(r, node)){
			return 1;
		}
	}
	return 0;
}

int main(){
	fastio;

	cin >> n >> m >> s;
	s--;

	forn(i, m){
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		// adj[v].pb(u);
	}

	par[s] = -1;
	vis[s] = 1;
	ntime[s] = -1;
	c_time = 1;

	forstl(r, adj[s]){
		// cout << "GOGO " << r << endl;
		if(ntime[r]>0){
			// cout << "GG" << endl;
			r1.pb(s);
			r1.pb(r);
			while(r!=-1){
				r2.pb(r);
				r = par[r];
			}
			reverse(all(r2));
			break;
		}
		// cout << "WEN" << endl;
		ntime[r] = c_time;
		par[r] = s;
		bool kk = dfs(r, s);
		if(kk) break;
		c_time++;
	}
	// cout << "DONE" << endl;
	
	if(r1.size()>0){
		cout << "Possible" << ln;
		cout << r1.size() << ln;
		forstl(r, r1) cout << r+1 << " ";
		cout << ln; 
		cout << r2.size() << ln;
		forstl(r, r2) cout << r+1 << " ";
		cout << ln; 
	}
	// if(cycle.size()>0){
	// 	v32 r1;
	// 	r1.pb(s);
	// 	r1.pb(cycle[0]);
	// 	reverse(all(cycle));
	// 	cout << "Possible" << ln;
	// 	cout << r1.size() << ln;
	// 	forstl(r, r1) cout << r+1 << " ";
	// 	cout << ln; 
	// 	cout << cycle.size() << ln;
	// 	forstl(r, cycle) cout << r+1 << " ";
	// 	cout << ln; 
	// }
	else{
		cout << "Impossible" << ln;
	}

	return 0;
}