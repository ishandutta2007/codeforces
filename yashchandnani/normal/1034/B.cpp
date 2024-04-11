#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
bool dfs(int a, int layer, const vector<vi>& g, vi& btoa,
			vi& A, vi& B) {
	if (A[a] != layer) return 0;
	A[a] = -1;
	trav(b, g[a]) if (B[b] == layer + 1) {
		B[b] = -1;
		if (btoa[b] == -1 || dfs(btoa[b], layer+2, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(const vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), -1);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		trav(a, btoa) if(a != -1) A[a] = -1;
		rep(a,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay += 2) {
			bool islast = 0;
			next.clear();
			trav(a, cur) trav(b, g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && B[b] == -1) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			trav(a, next) A[a] = lay+1;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,sz(g)) {
			if(dfs(a, 0, g, btoa, A, B))
				++res;
		}
	}
}
vector<vi> g;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	if(n>=9||m>=9){
		if(n<9) swap(n,m);
		if(m==1){
			int l = n%6;
			if(l==4) l =2;
			else if(l==5) l=1;
			cout<<n-l;
			return 0;
		}
		cout<<1ll*n*m-(1ll*n*m)%2;
		return 0;
	}
	g.resize(n*m);
	rep(i,n) rep(j,m){
		int k = 3,l = 0;
		while(k>=0){
			if(i+k>=0&&i+k<n&&j+l>=0&&j+l<m) g[i*m+j].pb((i+k)*m+j+l);k--,l++;
		}
		k = -1,l=2;
		while(k>=-3){
			if(i+k>=0&&i+k<n&&j+l>=0&&j+l<m) g[i*m+j].pb((i+k)*m+j+l);
			k--,l--;
		}
		k = -2,l=-1;
		while(k<=0){
			if(i+k>=0&&i+k<n&&j+l>=0&&j+l<m) g[i*m+j].pb((i+k)*m+j+l);k++,l--;
		}
		k = 1,l=-2;
		while(k<=2){
			if(i+k>=0&&i+k<n&&j+l>=0&&j+l<m) g[i*m+j].pb((i+k)*m+j+l);k++,l++;
		}
	}
	vi btoa(n*m,-1);
	int ans = hopcroftKarp(g,btoa);
	cout<<ans;
	return 0;
}