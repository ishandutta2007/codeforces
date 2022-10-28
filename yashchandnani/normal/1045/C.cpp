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
set<pii> ed;
vi g[100009],P;
vector<vi> treeJump(vi& P){
		int on = 1, d = 1;
			while(on < sz(P)) on *= 2, d++;
				vector<vi> jmp(d, P);
					repA(i,1,d-1) rep(j,sz(P))
								jmp[i][j] = jmp[i-1][jmp[i-1][j]];
						return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
		rep(i,sz(tbl))
					if(steps&(1<<i)) nod = tbl[i][nod];
			return nod;
}
int dep[100009];
bool vis[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m,qq;cin>>n>>m>>qq;
	P.resize(n,0);
	rep(i,m){
		int u,v;cin>>u>>v;
		u--,v--;
		g[u].pb(v);g[v].pb(u);
		ed.insert(mp(u,v));
	}
	queue<int> q;
	q.push(0);vis[0]=1;
	while(!q.empty()){
		int z = q.front();
		q.pop();
		trav(i,g[z]){
			if(!vis[i]){
				vis[i] = 1;
				P[i] = z;
				dep[i] = dep[z]+1;
				q.push(i);
			}
		}
	}
	vector<vi> tbl = treeJump(P);
	int on = 1, d = 1;
	while(on < sz(P)) on *= 2, d++;
	rep(i,qq){
		int u,v;cin>>u>>v;u--,v--;
		if(dep[u]>dep[v]) swap(u,v);
		int ans = dep[v] - dep[u];
		v = jmp(tbl,v,dep[v]-dep[u]);
		if(u!=v){
			repD(i,d-1,0){
				if(tbl[i][u]!=tbl[i][v]){
					u = tbl[i][u],v=tbl[i][v];
					ans+=1<<(i+1);
				}
			}
			if(ed.find(mp(u,v))!=ed.end()||ed.find(mp(v,u))!=ed.end()) ans++;
			else ans+=2;
		}
		cout<<ans<<'\n';
	}
	return 0;
}