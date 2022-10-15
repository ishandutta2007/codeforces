// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
#define double long double
// #define i128 long long
// #define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
// const int mod[]={998244353,(int)1e9+7};
const int mod=998244353;
const int base[]={12321,32123};
const double EPS=8e-6;
const double pi=acos(-1);
const int INF=1e12;
const int N=1000007;
mt19937 rng(1235);

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(range(A), 0);
		fill(range(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	// void atMostOne(const vi& li) { // (optional)
	// 	if (sz(li) <= 1) return;
	// 	int cur = ~li[0];
	// 	rep(i,2,sz(li)) {
	// 		int next = addVar();
	// 		either(cur, ~li[i]);
	// 		either(cur, next);
	// 		either(~li[i], next);
	// 		cur = ~next;
	// 	}
	// 	either(cur, ~li[1]);
	// }

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,2*N) if (!comp[i]) dfs(i);
		rep(i,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int n;
vector<pii> edges;
int par[N],sz[N];
int ans=1;
int fnd(int u){
  if (par[u]==u) return u;
  return par[u]=fnd(par[u]);
}
void unite(int u,int v){
  int pu=fnd(u), pv=fnd(v);
  if (pu==pv) return;
  int ret=sz[pv]*sz[pu]%mod;
  ret=ret*ret%mod;
  ans=ans*ret%mod;
  par[pu]=pv, sz[pv]+=sz[pu];
}
signed main(){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout.precision(15);
  cin>>n;
  rep(i,n) par[i]=i, sz[i]=1;
  rep(i,n-1){
    int u,v;
    cin>>u>>v;
    unite(u,v);
  }
  for (int i=1;i<n;++i) ans=ans*(2*i-1)%mod;
  cout<<ans;
  return 0;
}