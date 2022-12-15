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
#define ln endl
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

int n;
v32 adj[1005];
int done[1005];
v32 gl;

void dfs2(int node, int par){
	gl.pb(node);
	forstl(r,adj[node]){
		if(r == par) continue;
		dfs2(r,node);
	}
}

void dfs(int node, int par){
	// cout<<node+1<<" "<<par+1<<ln;
	done[node] = 1;
	forstl(r,adj[node]){
		if(r == par) continue;
		dfs(r,node);
	}
}

int main(){
	fastio;

	cin>>n;
	forn(i,n) done[i] = 0;
	int deg[n] = {0};
	forn(i,n-1){
		int u,v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
		deg[u]++;
		deg[v]++;
	}

	while(true){
		int take = -1, left = 0;
		v32 adj2[n];
		forn(i,n){
			if(done[i] == 0 && deg[i]>1){
				take = i;
			}
			if(done[i] == 0) left++;
		}

		if(left == 2){
			int g1 = -1, g2 = -1;
			forn(i,n){
				if(g1 == -1 && done[i] == 0) g1 = i;
				else if(done[i] == 0) g2 = i;
			}
			cout<<"? "<<g1+1<<" "<<g2+1<<ln;
			int x; cin>>x;
			if(x == -1) break;
			cout<<"! "<<x<<ln;
			break;
		}
		if(left == 1){
			int g1 = -1;
			forn(i,n){
				if(done[i] == 0) g1 = i;
			}
			cout<<"! "<<g1+1<<ln;
			break;
		}
		int tk1 = -1, tk2 = -1;
		forstl(r,adj[take]){
			if(tk1 == -1 && done[r] == 0) tk1 = r;
			else if(done[r] == 0) tk2 = r;
		}

		cout<<"? "<<tk1+1<<" "<<tk2+1<<ln;
		int x; cin>>x; 
		if(x == -1) break;
		x--;
		
		gl.clear();	
		bool p = 0;
		dfs2(tk1,take);
		forstl(r,gl){
			if(x == r) p = 1;
		}
		if(p){
			deg[tk1] -= 1;
			dfs(take,tk1);
			continue;
		}
		gl.clear();
		dfs2(tk2,take);
		forstl(r,gl){
			if(x == r) p = 1;
		}
		if(p){
			deg[tk2] -= 1;
			dfs(take,tk2);
			continue;
		}
		deg[take] -= 2;
		dfs(tk1,take);
		dfs(tk2,take);
		continue;
	}


	return 0;
}