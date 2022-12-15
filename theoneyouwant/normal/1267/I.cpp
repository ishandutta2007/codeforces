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

char c;
int a[1005][1005];
void end(){
	cout<<"!"<<ln;
}
int ask(int i,int j){
	if(a[i][j]!=0) return a[i][j]; 
	cout<<"? "<<i<<" "<<j<<ln;
	cin>>c;
	int ret = (c=='>') ? 1:-1; 
	a[i][j] = ret;
	return ret;
}
vector<int> adj[LIM];
vector<bool> visited;
vector<int> ans;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}
void topological_sort(int n){
    visited.assign(n,0);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
int main(){
	fastio;
	int tests;
	cin>>tests;
	while(tests--){
		int n;
		cin>>n;
		forn(i,2*n+1) adj[i].clear();
		forn(i,2*n+1) forn(j,2*n+1) a[i][j]=0;
		v32 lose;
		int m[2*n+1]={0};
		forn(i,n){
			if(ask(2*i+1,2*i+2)>0) m[2*i+2]=1,lose.pb(2*i+2);
			else lose.pb(2*i+1),m[2*i+1]=1;
		}
		forn(i,n){
			forsn(j,i+1,n){
				if(ask(lose[i],lose[j])>0) adj[lose[i]].pb(lose[j]);
				else adj[lose[j]].pb(lose[i]);
			}
		}
		topological_sort(2*n+1);
		int xx=0;
		forstl(it,ans) if(m[it]>0){
			xx = it; break;
		}
		memset(m,0,sizeof(m));
		m[xx]=1;
		m[0]=1;
		if(xx&1) m[xx+1]=1;
		else m[xx-1]=1;
		forn(i,2*n+1) adj[i].clear();
		forn(i,2*n){
			if(m[i+1]) continue;
			forsn(j,i+1,2*n){
				if(m[j+1]) continue;
				if(ask(i+1,j+1)>0) adj[i+1].pb(j+1);
				else adj[j+1].pb(i+1);
			}
		}
		topological_sort(2*n+1);
		v32 v;
		forstl(it,ans) if(m[it]==0){
			v.pb(it);
		}
		// dbg(v);
		// dbg(xx,v[n-1]);
		ask(xx,v[n-2]);
		end();
	}

	return 0;
}