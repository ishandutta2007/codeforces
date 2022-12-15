//By TheOneYouWant
#pragma GCC optimize ("-O2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const int LIM=1e3+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,l,s,t;
vector<pair<int,ll>> adj[LIM], adjchk[LIM];

const ll INF = 1e18;

void dijkstra(int ss, vector<ll> & d, vector<int> & p) {
    d.assign(n, INF);
    p.assign(n, -1);

    d[ss] = 0;
    using pii = pair<ll, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, ss});

    bool gotone = 0, gottwo = 0;

    while (!q.empty()) {
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        if(v == s) gotone = 1;
        if(v == t) gottwo = 1;
        if(gotone == 1 && gottwo == 1) return;

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

signed main(){
	fastio;

	cin>>n>>m>>l>>s>>t;
	vector<tuple<int,int,ll>> edges;
	vector<tuple<int,int,ll>> answer;
	forn(i,m){
		int u, v;
		ll w;
		cin>>u>>v>>w;
		if(w != 0){
			adj[u].pb(mp(v,w));
			adj[v].pb(mp(u,w));
			answer.pb({u,v,w});
		}
		else{
			edges.pb({u,v,w});
		}
	}

	forstl(r,edges){
		ll u, v, w;
		tie(u, v, w) = r;
		v64 d1;
		v32 p;
		adj[u].pb(mp(v,0));
		adj[v].pb(mp(u,0));
		dijkstra(u,d1,p);
		ll add = max(1ll, l-d1[s]-d1[t]);
		adj[u].pop_back();
		adj[v].pop_back();
		adj[u].pb(mp(v,add));
		adj[v].pb(mp(u,add));
		answer.pb({u,v,add});
	}

	v64 d;
	v32 p;
	dijkstra(s, d, p);
	if(d[t] == l){
		cout<<"YES"<<ln;
		forstl(r,answer){
			ll u, v, w;
			tie(u, v, w) = r;
			cout<<u<<" "<<v<<" "<<w<<ln;
		}
	}
	else cout<<"NO"<<ln;

	return 0;
}