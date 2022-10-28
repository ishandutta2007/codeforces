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

vector<pair<vi,vi>> v;
map<vi,int> str;
int qry(vi q){
	if(sz(q)<2) return 0;
	sort(all(q));
	if(str.find(q)!=str.end()) return str[q];
	cout<<"? "<<sz(q)<<"\n";
	trav(i,q) cout<<i<<' ';
	cout<<endl;
	int x;cin>>x;
	return str[q] = x;
}
int cal(vi q,int i,int fg){
	rep(j,i){
		if(!fg) trav(k,v[j].fst) q.pb(k);
		else trav(k,v[j].snd) q.pb(k);
	}
	return qry(q);
}

int que(vi a){
	vi q=a,q2;
	trav(i,v){
		trav(j,i.fst) q.pb(j),q2.pb(j);
	}
	if(qry(q)==qry(q2)) {
		q = a,q2.clear();
		trav(i,v){
			trav(j,i.snd) q.pb(j),q2.pb(j);
		}
		if(qry(q)==qry(q2)) return -1;
		int lo = 0,hi = sz(v)-1;
		while(lo<hi){
			int m = (lo+hi)/2;
			q = a;
			int aa=cal(q,m+1,1);
			q.clear();
			int bb = cal(q,m+1,1);
			if(aa==bb) lo = m+1;
			else hi = m;
		}
		return lo;
	}
	int lo = 0,hi = sz(v)-1;
	while(lo<hi){
		int m = (lo+hi)/2;
		q = a;
		int aa=cal(q,m+1,0);
		q.clear();
		int bb = cal(q,m+1,0);
		if(aa==bb) lo = m+1;
		else hi = m;
	}
	return lo;
}
int qe(vi a,vi b){
	vi q;
	trav(i,a) q.pb(i);
	trav(i,b) q.pb(i);
	return qry(q);
}
vi g[609];
bool vis[609];
int p[609],l[609];
vi cycle;
void dfs(int u,int v,int h){
	vis[u] = 1;
	p[u] = v;
	l[u] = h;
	trav(i,g[u]){
		if(!vis[i]){
			dfs(i,u,1-h);
		}
		else if(l[i]==l[u]){
			vi a,b;
			while(p[u]!=-1) a.pb(u),u = p[u];
			a.pb(u);
			while(p[i]!=-1) b.pb(i),i = p[i];
			reverse(all(b));
			trav(i,b) a.pb(i);
			cout<<"N "<<sz(a)<<'\n';
			trav(i,a) cout<<i<<' ';
			cout<<endl;
			exit(0);
		}
	}
}
void conn(vi a){
	dfs(a[0],-1,0);
	trav(i,a) if(!vis[i]) exit(-1);
	fill(vis);
}
void join(vi a,vi b){
	vi q;
	int lo = 0,hi = sz(a)-1;
	while(lo<hi){
		int m = (lo+hi)/2;
		vi q = b;
		rep(i,m+1) q.pb(a[i]);
		if(qry(q)) hi = m;
		else lo =m+1;
	}
	vi aa = a;
	int x = a[lo];
	a.clear();
	a.pb(x);
	swap(a,b);
	lo = 0,hi = sz(a)-1;
	while(lo<hi){
		int m = (lo+hi)/2;
		vi q = b;
		rep(i,m+1) q.pb(a[i]);
		if(qry(q)) hi = m;
		else lo =m+1;
	}
	g[b[0]].pb(a[lo]);
	g[a[lo]].pb(b[0]);
}
void odd_cycle(bool fg){
	int ix =0;
	vi kk;
	repA(i,1,600){
		if(sz(g[i])&&!vis[i]){
			kk.pb(i);
			ix++;
			p[i] = -1;
			dfs(i,-1,0);
		}
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	v.resize(n);
	rep(i,n) v[i].fst.pb(i+1);
	vi l,r;
	while(sz(v)){
		vi x = v.back().fst,y = v.back().snd;
		v.pop_back();
		int i = que(x);
		if(i==-1){
			i = que(y);
		}
		if(i==-1){
			trav(i,x) l.pb(i);
			trav(i,y) r.pb(i);
		}
		else{
			int a1 = qe(x,v[i].fst),a2 = qe(x,v[i].snd),a3 = qe(y,v[i].fst),a4 = qe(y,v[i].snd);
			if(a1) join(x,v[i].fst);
			if(a2) join(x,v[i].snd);
			if(a3) join(y,v[i].fst);
			if(a4) join(y,v[i].snd);
			if(a2==0&&a3==0){
				trav(j,x) v[i].snd.pb(j);
				trav(j,y) v[i].fst.pb(j);
			}
			else if(a1==0&&a4==0){
				trav(j,x) v[i].fst.pb(j);
				trav(j,y) v[i].snd.pb(j);
			}
			else{
				odd_cycle(n==599);
				exit(0);
			}
		}

	}
	cout<<"Y "<<sz(l)<<'\n';
	trav(i,l) cout<<i<<' ';
	cout<<endl;
	
	return 0;
}