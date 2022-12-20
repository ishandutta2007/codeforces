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
const int LIM=3e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
v32 adj[LIM];

const int INF = 1000000000;

void dijkstra(int s, v32 & d, v32 & p){
	d.assign(n, INF);
	p.assign(n, -1);

	d[s] = 0;
	set<p32> q;
	q.insert({0, s});
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		forstl(r, adj[v]){
			int to = r;
			if(d[v] + 1 < d[to]) {
				q.erase({d[to], to});
				d[to] = d[v] + 1;
				p[to] = v;
				q.insert({d[to], to});
			}
		}
	}
}


int link[LIM] = {0};
int sz[LIM] = {0};
int deg[LIM] = {0};

int find(int x){
	if(x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	link[b] = a;
}

int main(){
	fastio;

	cin>>n>>m;
	forn(i,m){
		int u,v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	v32 d, p;
	dijkstra(0, d, p);

	int ans = INF;

	int ans1 = d[n-1];
	int ans2 = INF;

	forn(i,n){
		if(d[i] == 2){
			ans2 = 4;
		} 
	}

	int ans3 = INF;

	forn(i,n) link[i] = i;
	forn(i,n) sz[i] = 1;

	forsn(i,1,n-1){
		forstl(r,adj[i]){
			if(r == 0) continue;
			if(r == n-1) continue;
			unite(i, r);
			deg[i]++;
		}
	}
	forsn(i,1,n){
		if(d[i] <= 1 && deg[i] < sz[find(i)]-1) ans3 = 5; 
	}

	ans = min({ans1, ans2, ans3});

	if(ans == INF){
		cout<<-1<<ln;
	} 
	else{
		cout<<ans<<ln;
		stack<int> s;

		if(ans == ans1){
			int ptr = n-1;
			while(ptr != -1){
				s.push(ptr);
				ptr = p[ptr];
			}
			
		}
		else if(ans == ans2){
			s.push(n-1);
			s.push(0);
			int v = -1;
			forn(i,n) if(d[i] == 2) v = i;
			while(v != -1){
				s.push(v);
				v = p[v];
			}
		}
		else if(ans == ans3){
			int v = -1;
			forsn(i,1,n){
				if(d[i] <= 1 && deg[i] < sz[find(i)]-1) v = i;
			}
			v32 adj2[LIM];
			forsn(i,1,n-1){
				forstl(r,adj[i]){
					if(r != 0 && r != n-1) adj2[i].pb(r);
				}
			}
			forn(i,n){
				adj[i].clear();
				forstl(r,adj2[i]) adj[i].pb(r);
			}

			d.clear();
			p.clear();
			dijkstra(v, d, p);
			int f = -1;
			forn(i,n){
				if(d[i] == 2) f = i;
			}
			s.push(n-1);
			s.push(v);
			while(f != v){
				s.push(f);
				f = p[f];
			}
			s.push(v);
			s.push(0);
		}

		while(!s.empty()){
				cout<<s.top()+1<<" ";
				s.pop();
			} 
		cout<<ln;
	}

	return 0;
}