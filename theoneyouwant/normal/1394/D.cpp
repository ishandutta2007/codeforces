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

int n;
ll t[LIM], h[LIM];
ll deg[LIM];
ll in[LIM], out[LIM];
v64 adj[LIM];
ll ans = 0;
bool visited[LIM];
ll up[LIM], down[LIM];

void solve(int node, int par){
	ll sum_down = 0;
	v64 up_down;
	ll child = 0;
	visited[node] = 1;
	forstl(r, adj[node]){
		if(visited[r]) continue;
		child++;
		solve(r, node);
		sum_down += down[r];
		up_down.pb(up[r]-down[r]);
	}
	sort(up_down.begin(), up_down.end(), greater<ll>());
	ll curr_sum = 0;

	forn(i, up_down.size()+1){
		ll outn = child-i, inn = i, add = 1;
		if(par == -1) add = 0;
		ll upmin = min(outn+out[node]+add,inn+in[node]);
		ll downmin = min(outn+out[node],inn+in[node]+add);

		up[node] = max(up[node], sum_down+curr_sum+upmin*t[node]);
		down[node] = max(down[node], sum_down+curr_sum+downmin*t[node]);

		if(i != up_down.size()) curr_sum += up_down[i];
	}

}

int main(){
	fastio;

	cin>>n;
	forn(i,n) cin>>t[i];
	forn(i,n) cin>>h[i];
	forn(i,n-1){
		int u,v; cin>>u>>v;
		u--; v--;
		deg[u]++; deg[v]++;
		if(h[u] == h[v]){
			adj[u].pb(v);
			adj[v].pb(u);
		}
		else{
			if(h[u]>h[v]){
				in[u]++;
				out[v]++;
			}
			else{
				in[v]++;
				out[u]++;
			}
		}
	}
	forn(i,n){
		ans += deg[i]*t[i];
		ll r = min(in[i], out[i]);
		in[i] -= r;
		out[i] -= r;
		ans -= r*t[i];
	}

	forn(i,n){
		if(!visited[i]){
			solve(i, -1);
			// cout<<i<<" "<<max(up[i], down[i])<<ln;
			ans -= max(up[i], down[i]);
		}
	}
	cout<<ans<<ln;

	return 0;
}