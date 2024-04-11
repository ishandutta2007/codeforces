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

vector<v32> gr;
int sz[int(1e6)+10];
int n;

int ssum(v32 &v) {

	map <int, int> m;
	v32 w;
	for(int x : v)
		m[x]++;
	for(auto p : m) {
		if(p.second % 2) {
			w.push_back(p.first);
			if(p.second >= 3)
				m[p.first*2] += (p.second-1)/2;
		} else {
			w.push_back(p.first);
			w.push_back(p.first);
			if(p.second >= 4)
				m[p.first*2] += (p.second-2)/2;
		}
	}
//	forn(i, v.size())
//		cout << v[i] << " ";
//cout << endl;
	bitset<int(1e6)> b;
	b[0] = 1;
	for(int x : w) {
		b |= (b << x);
	}
	//cout << b << endl;
	int mid = (n-1)/2;
	while(!b[mid]) mid--;
	return mid;
}

int h[int(1e6)+10], p[int(1e6)+10];

void dfs_deep(int v, int par) {
	h[v] = h[par]+1;
	p[v] = par;
	for(int u : gr[v])
		if(u != par)
			dfs_deep(u,v);
}

vector<int> Centroid(vector<vector<int>> &g) {
        int n = g.size();
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}

void dfs_sz(int v, int par) {
	sz[v] = 1;
	for(int u : gr[v])	
		if(u != par) {
			dfs_sz(u,v);
			sz[v] += sz[u];	
		}
}

ll dfs_ans(int v,int par) {
	ll ans = ll(sz[v]); 
	for(int u : gr[v])	
		if(u != par) {
			ans += dfs_ans(u,v);
		}	
	return ans;
}

ll ans(int ctr) {
	dfs_sz(ctr, -1);
	v32 v;
	for(int u : gr[ctr])
		v.push_back(sz[u]);
	int mid = ssum(v);
	//cout << mid << endl;
	ll ans = dfs_ans(ctr, -1);
	ans += ll(mid)*ll(n - 1 - mid);
	return ans;
}

int main() {
	fastio;
	cin >> n;
	gr.resize(n);
	forn(i, n-1) {
		int p; cin >> p;
		p--;
		gr[p].push_back(i+1);
		gr[i+1].push_back(p);
	}
	v32 ctr = Centroid(gr);
	//cout << ctr << endl;
	ll res = ans(ctr[0]);
	if(ctr.size() > 1)
		res = max(res, ans(ctr[1]));
	cout << res << endl;
	return 0;
}