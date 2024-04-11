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
vector<vi> g,g2;
bool vis[2009];
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
bool inst(pair<int,pii> a,pair<int,pii> b){
	if(a.fst<b.snd.snd&&a.fst>b.snd.fst&&b.fst<a.snd.snd&&b.fst>a.snd.fst) return 1;
	return 0;
}
void dfs(int v){
	vis[v] = 1;
	trav(i,g2[v]) if(!vis[i]) dfs(i);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	map<int,vi> r,c;
	map<pii,int> pts;
	rep(i,n){
		int x,y;cin>>x>>y;
		pts[mp(x,y)] = i;
		r[x].pb(y);
		c[y].pb(x);
	}
	vector<pair<int,pii>> rr,cc;
	trav(i,c){
		sort(all(i.snd));
		repA(j,1,sz(i.snd)-1){
			cc.pb(mp(i.fst,mp(i.snd[j-1],i.snd[j])));
		}
	}
	trav(i,r){
		sort(all(i.snd));
		repA(j,1,sz(i.snd)-1){
			rr.pb(mp(i.fst,mp(i.snd[j-1],i.snd[j])));
		}
	}
	g.resize(sz(rr)+sz(cc));
	rep(i,sz(rr)){
		rep(j,sz(cc)){
			if(inst(rr[i],cc[j])) {g[i].pb(sz(rr)+j),g[sz(rr)+j].pb(i);}
		}
	}
	vi btoa(sz(g),-1);
	int fns = hopcroftKarp(g,btoa)/2;
	int xx=fns;
	int m = sz(rr)+sz(cc);
	xx = m-fns;
	fns = 2*n - (m - fns);
	g2.resize(m);
	rep(i,sz(rr)) {
		trav(j,g[i]) {
			if(j!=btoa[i]) g2[i].pb(j);
			else g2[j].pb(i);
		}
	}
	rep(i,sz(rr)) if(!vis[i]&&btoa[i]==-1) dfs(i);
	UF r1(n),c1(n);	
	rep(i,sz(rr)){
		if(vis[i]){
			xx--;
			r1.join(pts[mp(rr[i].fst,rr[i].snd.fst)],pts[mp(rr[i].fst,rr[i].snd.snd)]);
		}
	}
	repA(i,sz(rr),m-1){
		if(!vis[i]){
			xx--;
			i-=sz(rr);
			c1.join(pts[mp(cc[i].snd.fst,cc[i].fst)],pts[mp(cc[i].snd.snd,cc[i].fst)]);
			i+=sz(rr);
		}
	}
	assert(xx==0);
	vector<pair<pii,pii>> ans;
	trav(i,c){
		rep(j,sz(i.snd)){
			int k =j;
			while(k+1<sz(i.snd)&&c1.same_set(pts[mp(i.snd[j],i.fst)],pts[mp(i.snd[k+1],i.fst)])) k++;
			ans.pb(mp(mp(i.fst,i.snd[j]),mp(i.fst,i.snd[k])));
			j = k;
		}
	}
	fns-=sz(ans);
	cout<<sz(ans)<<'\n';
	trav(i,ans) cout<<i.fst.snd<<' '<<i.fst.fst<<' '<<i.snd.snd<<' '<<i.snd.fst<<'\n';
	ans.clear();
	trav(i,r){
		rep(j,sz(i.snd)){
			int k =j;
			while(k+1<sz(i.snd)&&r1.same_set(pts[mp(i.fst,i.snd[j])],pts[mp(i.fst,i.snd[k+1])])) k++;
			ans.pb(mp(mp(i.fst,i.snd[j]),mp(i.fst,i.snd[k])));
			j = k;
		}
	}
	fns-=sz(ans);
	cout<<sz(ans)<<'\n';
	trav(i,ans) cout<<i.fst.fst<<' '<<i.fst.snd<<' '<<i.snd.fst<<' '<<i.snd.snd<<'\n';
	return 0;
}