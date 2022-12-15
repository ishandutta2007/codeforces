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

v32 adj[LIM];
ll fact[LIM];
ll invfact[LIM];

const ll MX = 405;

ll fastpow(ll a, ll p){
	if(p == 0) return 1;
	ll z = fastpow(a, p/2);
	z = (z*z)%MOD;
	if(p%2) z = (a*z)%MOD;
	return z;
}

ll ncr(ll n, ll r){
	ll ans = (fact[n] * invfact[r]) % MOD;
	ans = (ans * invfact[n-r]) % MOD;
	return ans;
}

ll dp[MX][MX];
ll prob[MX][MX];

void dp_calc(){
	prob[0][0] = 1;
	forn(i,MX){
		forn(j,MX){
			if(i>0) prob[i][j] += (prob[i-1][j] * invfact[2]) % MOD;
			if(j>0) prob[i][j] += (prob[i][j-1] * invfact[2]) % MOD;
			prob[i][j] %= MOD;
		}
	}
	forsn(i,1,MX){
		forn(j,MX){
			forn(k,j){
				dp[i][j] += (prob[i-1][k] * invfact[2]) % MOD;
			}
			dp[i][j] %= MOD;
		}
	}
	forn(i,MX){
		dp[0][i] = 1;
	}
	forn(i,MX){
		dp[i][0] = 0;
	}
}

void pre(){
	fact[0] = 1;
	forsn(i,1,LIM){
		fact[i] = (fact[i-1] * i) % MOD;
	}
	invfact[LIM-1] = fastpow(fact[LIM-1], MOD-2);
	rforn(i,LIM-2){
		invfact[i] = (invfact[i+1] * (i+1)) % MOD;
	}
}

int n, l;
int timer;
v32 tin, tout;
vv32 up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int main(){
	fastio;

	cin >> n;

	pre();
	dp_calc();

	forn(i, n-1){
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	int dist[n] = {0};
	bool vis[n] = {0};

	ll ans = 0;

	forn(i,n){
		queue<int> q;
		
		forn(i,n){
			dist[i] = 0;
			vis[i] = 0;
		}

		q.push(i);
		vis[i] = 1;

		while(!q.empty()){
			auto t = q.front();
			q.pop();
			forstl(r, adj[t]){
				if(vis[r]) continue;
				vis[r] = 1;
				dist[r] = dist[t] + 1;
				q.push(r);
			}
		}

		preprocess(i);

		forn(j,n){
			forsn(k,j+1,n){
				if(j == k) continue;
				int c = lca(j, k);
				
				// cout << "calculating " ;
				// cout << i << " " << j << " " << k << ln;
				int t1 = dist[k] - dist[c], t2 = dist[j] - dist[c];
				// cout << t1 << " " << t2 << " " << dp[t1][t2] << ln;
				ans += dp[t1][t2];
				ans %= MOD;
				// cout << "now ans is " << ans << ln;
			}
		}
	}

	ans = (ans * fastpow(n, MOD-2)) % MOD;

	cout << ans << ln;

	return 0;
}