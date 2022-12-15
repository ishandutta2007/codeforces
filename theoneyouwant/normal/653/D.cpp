//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define int long long int
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
const int LIM=50+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct EdmondKarp{
	int n; 
	vector<vector<int>> cap;
	vector<vector<int>> adj;

	EdmondKarp(int n){
		this->n = n;
		cap.assign(n, vector<int>(n, 0));
		adj.assign(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				adj[i][j] = j;
			}
		}
	}

	void addEdge(int u, int v, int w){
		cap[u][v] = w;
	}

	int bfs(int s, int t, vector<int>& parent){
		fill(parent.begin(), parent.end(), -1);
		parent[s] = -2;
		queue<pair<int,int>> q;
		q.push({s, 2e18});

		while(!q.empty()){
			int cur = q.front().first;
			int flow = q.front().second;
			q.pop();
			forstl(nxt, adj[cur]){
				if(parent[nxt] == -1 && cap[cur][nxt] > 0){
					parent[nxt] = cur;
					int new_flow = min(flow, cap[cur][nxt]);
					if(nxt == t){
						return new_flow;
					}
					q.push({nxt, new_flow});
				}
			}
		}
		return 0;
	}

	int maxflow(int s, int t){
		int flow = 0;
		vector<int> parent(n);
		int new_flow;

		while(new_flow = bfs(s, t, parent)){
			flow += new_flow;
			int cur = t;
			while(cur != s){
				int prev = parent[cur];
				cap[prev][cur] -= new_flow;
				cap[cur][prev] += new_flow;
				cur = prev;
			}
		}
		return flow;
	}
};

vp32 adj[LIM];

signed main(){
	fastio;

	int n, m, x;
	cin>>n>>m>>x;

	forn(i,m){
		int a, b, c;
		cin>>a>>b>>c;
		a--; b--;
		adj[a].pb(mp(b,c));
	}

	ld l = 0, r = 1e9;

	forn(iter,200){
		ld mid = (l+r)/2;
		EdmondKarp f(n);
		assert(mid > 0);
		forn(i,n){
			forstl(j, adj[i]){
				f.addEdge(i, j.fi, floor(((ld)j.se) / mid));
			}
		}
		ld ans = f.maxflow(0, n-1);
		if(ans >= x){
			l = mid;
		}
		else{
			r = mid;
		}
	}	

	cout<<setprecision(10)<<fixed;
	cout<<l * x<<ln;

	return 0;
}