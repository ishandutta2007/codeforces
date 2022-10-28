#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
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

vector<vi> g;
bool vis[5009][5009];
struct UF {
		vi e;
			UF(int n) : e(n, -1) {}
				bool same_set(int a, int b) { return find(a) == find(b); }
					int size(int x) { return -e[find(x)]; }
						int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
							void join(int a, int b) {
										a = find(a), b = find(b);
												if (a == b) return;
														if (e[a] > e[b]) swap(a, b);
																e[a] += e[b]; e[b] = a;
																	}
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	g.resize(n);
	rep(i,m){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		if(n<=5000) vis[u][v] = vis[v][u] = 1;
	}
	if(n<=5000){
		UF dsu(n);
		rep(i,n) rep (j,i) {
			if(!vis[i][j]) dsu.join(i,j);
		}
		int ans = 0;
		rep(i,n) if(dsu.find(i)==i) ans++;
		if(ans) cout<<ans-1;
		else cout<<0;
	}
	else{
		UF dsu(n);
		int gg=-1;
		rep(i,n){
			if(sz(g[i])>4000){
				sort(all(g[i]));
				int lst = 0;
				trav(j,g[i]){
					repA(k,lst,j-1) dsu.join(i,k);
					lst=j+1;
				}
				repA(k,lst,n-1) dsu.join(i,k);
			}
			else{
				if(gg>=0) dsu.join(i,gg);
				gg=i;
			}
		}
		int ans = 0;
		rep(i,n) if(dsu.find(i)==i) ans++;
		if(ans) cout<<ans-1;
		else cout<<0;
	}
	return 0;
}