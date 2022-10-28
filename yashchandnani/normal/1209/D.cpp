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
vi g[100009];
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
int cnt[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int k;cin>>k;
	rep(i,k){
		int x,y;cin>>x>>y;
		g[x].pb(i);
		g[y].pb(i);
	}
	UF dsu(k);
	repA(i,1,n){
		repA(j,1,sz(g[i])-1){
			dsu.join(g[i][0],g[i][j]);
		}
	}
	repA(i,1,n){
		if(sz(g[i])){
			cnt[dsu.find(g[i][0])]++;
		}
	}
	int ans = 0;
	rep(i,k){
		if(dsu.find(i)==i) {
			if(dsu.size(i)>=cnt[i]) ans+=dsu.size(i)-cnt[i]+1; 
		}
	}
	cout<<ans;
	return 0;
}