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
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi,  madd = 0,cnt=1,mn=0;
	Node(int lo,int hi):lo(lo),hi(hi){
		cnt = hi-lo;
	} // Large interval of -inf
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L ) return;
		if ((L <= lo && hi <= R)) {
			madd += x;
			mn+=x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			mn = min(l->mn,r->mn);
			cnt =0;
			if(mn==r->mn) cnt+=r->cnt;
			if(mn==l->mn) cnt+=l->cnt;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};
vi g[200009];
int st[200009],en[200009];
int par[200009];
int t;
vector<pii> d[200009];
int ht[200009];
void dfs(int v,int p= -1,int h = 0){
	st[v] = t;
	par[v] = p;
	d[h].pb(mp(st[v],v));
	ht[v] = h;
	t++;
	trav(i,g[v]) if(i!=p) dfs(i,v,h+1);
	en[v] = t;
}
signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,q;cin>>n>>q;
	Node N(0,n);
	rep(i,n-1){
		int u,v;cin>>u>>v;u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	int cnt = 0;
	set<pii> ed,ed2;
	rep(i,200001) sort(all(d[i]));
	rep(i,q){
		int u,v;cin>>u>>v;u--,v--;
		bool fg = 0;
		int x = 1;
		if(u<v) swap(u,v);
		if(ed2.find(mp(u,v))!=ed2.end()) ed2.erase(mp(u,v)),x=-1;
		else ed2.insert(mp(u,v));
		if(st[u]<=st[v]&&st[v]<en[u]){
			auto it = upper_bound(all(d[ht[u]+1]),mp(st[v],v));
			it--;
			u = it->snd;
			N.add(st[u],en[u],x);
			N.add(st[v],en[v],-x);
		}
		else if(st[v]<=st[u]&&st[u]<en[v]){
			auto it = (upper_bound(all(d[ht[v]+1]),mp(st[u],u)));
			it--;
			v = it->snd;
			N.add(st[v],en[v],x);
			N.add(st[u],en[u],-x);
		}
		else{
			N.add(0,n,x);
			N.add(st[u],en[u],-x);
			N.add(st[v],en[v],-x);
		}
		if(N.mn!=0) cout<<0<<'\n';
		else cout<<N.cnt<<'\n';
	}
	return 0;
}