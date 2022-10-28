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
int r[200009];
vi g[200009];
pii ae[200009];
bool fg[200009];
set<int> del[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,k;cin>>n>>m>>k;
	int ans = 0;
	rep(i,m){
		int x,y;cin>>x>>y;
		g[x].pb(y);g[y].pb(x);
		ae[i] = mp(x,y);
	}
	vi a;
	repA(i,1,n){
		fg[i] = 1;
		r[i] = sz(g[i]);
		if(r[i]<k) a.pb(i),fg[i]=0;
	}
	ans = n;
	while(!a.empty()){
		int z = a.back();
		ans--;
		a.pop_back();
		trav(i,g[z]){
			if(fg[i]) {
				r[i]--;
				if(r[i]<k) a.pb(i),fg[i]=0;
			}
		}
	}
	vi fns;
	repD(i,m-1,0){
		fns.pb(ans);
		int x = ae[i].fst,y=ae[i].snd;
		if(fg[x]&&fg[y]) r[x]--,r[y]--;
		if(r[x]<k&&fg[x]) a.pb(x),fg[x]=0;
		if(r[y]<k&&fg[y]) a.pb(y),fg[y]=0;
		del[x].insert(y);
		del[y].insert(x);
		while(!a.empty()){
			int z = a.back();
			ans--;
			a.pop_back();
			trav(i,g[z]){
				if(fg[i]){
					if(del[z].find(i)!=del[z].end()) continue;
					r[i]--;
					if(r[i]<k) a.pb(i),fg[i]=0;
				}
			}
		}
	}
	reverse(all(fns));
	trav(i,fns) cout<<i<<'\n';
	return 0;
}