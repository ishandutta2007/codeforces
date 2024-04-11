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
vector<int> s[400009];
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
	int n,m,q;cin>>n>>m>>q;
	rep(i,q){
		int r,c;cin>>r>>c;
		s[r].pb(n+c);
		s[n+c].pb(r);
	}
	UF dsu(n+m+1);
	repA(i,1,n+m){
		trav(j,s[i]) dsu.join(s[i][0],j);
	}
	int ans=0;
	repA(i,1,n+m) if(dsu.find(i)==i) ans++;
	repA(i,1,n) if(dsu.find(i)==i&&sz(s[i])!=0) ans--;
	ans--;
	cout<<ans;
	


	return 0;
}