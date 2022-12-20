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
const int LIM=3005,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
v32 adj1[LIM];
v32 adj2[LIM];

vp32 max3[LIM], revmax3[LIM];
int bestans = -1;
v32 route;

int dist[LIM][LIM];
bool done[LIM][LIM];

void update_ans(int a, int b, int c, int d){
	int fin = 0;
	fin += dist[a][b] + dist[b][c] + dist[c][d];
	if((dist[a][b] == MOD) || (dist[b][c] == MOD) || (dist[c][d] == MOD)) return;
	if(fin > bestans){
		bestans = fin;
		route.clear();
		route.pb(a);
		route.pb(b);
		route.pb(c);
		route.pb(d);
	}
}

void solve(int a, int b){

	if(dist[b][a] == MOD) return;
	if(dist[b][a] == 0) return;

	forstl(r,max3[a]){
		forstl(k,revmax3[b]){
			if(a == k.se || b == r.se || k.se == r.se) continue;
			// FUCK SETS
			update_ans(k.se,b,a,r.se);
		}
	}
}

int main(){
	fastio;

	n = read(), m = read();

	forn(i,m){
		int u = read(), v = read();
		u--; v--;
		if(u == v) continue;
		if(done[u][v]) continue;
		done[u][v] = 1;
		adj1[u].pb(v);
		adj2[v].pb(u);
	}

	ll a = 0, b = 0;

	forn(i,n){
		int depth[n] = {0};
		forn(i,n) depth[i] = MOD;
		bool vis[n] = {0};
		depth[i] = 0;
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		while(!q.empty()){
			int t = q.front();
			q.pop();
			forstl(r, adj1[t]){
				if(vis[r]) continue;
				depth[r] = depth[t]+1;
				vis[r]=1;
				q.push(r);
			}
		}
		vp32 chk;
		forn(j,n){
			if(i == j) continue;
			if(depth[j] != MOD){
				chk.pb(mp(depth[j],j));
			}
		}
		forn(j,n){
			dist[i][j] = depth[j];
		}
		a += chk.size();
		sort(chk.begin(),chk.end(),greater<p32>());
		forn(j,min(3,(int)chk.size())) max3[i].pb(chk[j]);

		forn(i,n) depth[i] = MOD;
		depth[i] = 0;
		forn(i,n) vis[i]=0;
		q.push(i);
		vis[i]=1;
		while(!q.empty()){
			int t = q.front();
			q.pop();
			forstl(r, adj2[t]){
				if(vis[r]) continue;
				depth[r] = depth[t]+1;
				vis[r]=1;
				q.push(r);
			}
		}
		chk.clear();
		forn(j,n){
			if(i == j) continue;
			if(depth[j] != MOD){
				chk.pb(mp(depth[j],j));
			}
		}
		b += chk.size();
		sort(chk.begin(),chk.end(),greater<p32>());
		forn(j,min(3,(int)chk.size())) revmax3[i].pb(chk[j]);
	}
	forn(i,n){
		forn(j,n){
			solve(i,j);
		}
	}
	// cerr<<a<<" "<<b<<ln;

	forstl(r,route) cout<<r+1<<" ";
	cout<<ln;

	return 0;
}