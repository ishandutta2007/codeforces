#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	EACH(a, v)
		vti(a, x, m);
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

const int mxN=3e3;
int n, m, l[mxN], deg[mxN];
vt<ar<int, 2>> e;
vt<int> adj[mxN], odd;
bool ba[mxN][mxN], vis[mxN];

void dfs1(int u, vt<int> &v) {
	v.pb(u);
	vis[u]=1;
	EACH(x, adj[u])
		if(!vis[x])
			dfs1(x, v);
}

vt<vt<int>> comp(int v) {
	vt<vt<int>> r;
	FOR(n)
		if(!vis[i]&&(i==v||sz(adj[i]))) {
			r.pb({});
			dfs1(i, r.back());
		}
	return r;
}

vt<int> tour;
bool ba2[mxN][mxN];
bool ev[mxN];
void dfs2(int u) {
	while(sz(adj[u])) {
		int v=adj[u].back();
		adj[u].pop_back();
		if(ba2[u][v])
			continue;
		ba2[u][v]=ba2[v][u]=1;
		dfs2(v);
	}
	tour.pb(u);
}

void printsol(int u, int v) {
	dbg(u, v);
	vt<int> ol;
	//int k=1;
	EACH(f, e) {
		if(f[0]==v&&f[1]^u&&deg[f[1]]&1||f[1]==v&&f[0]^u&&deg[f[0]]&1) {
			ol.pb(v^f[0]^f[1]);
			dbg(v^f[0]^f[1]);
		}
		else {
			adj[f[0]].pb(f[1]);
			adj[f[1]].pb(f[0]);
			//ba2[f[0]][f[1]]=ba2[f[1]][f[0]]=k++;
		}
	}
	dfs2(u);
	reverse(all(tour));
	tour.pb(-2);
	EACH(x, ol) {
		tour.pb(x);
		tour.pb(v);
	}
	offset(1, tour);
	print(sz(tour));
	print(tour);
	exit(0);
}

void solve() {
	read(n, m);
	while(m--) {
		int u, v;
		read(u, v), --u, --v;
		//adj[u].pb(v);
		//adj[v].pb(u);
		e.pb({u, v});
		ba[u][v]=ba[v][u]=1;
		++deg[u], ++deg[v];
	}
	FOR(n)
		if(deg[i]&1)
			odd.pb(i);
	FOR(v, n) {
		vt<int> badodd;
		EACH(o, odd)
			if(o!=v&&!ba[o][v])
				badodd.pb(o);
		if(sz(badodd)>1)
			continue;
		if(sz(badodd)) {
			int u=badodd[0];
			//remove other odd edges
			EACH(f, e) {
				if(f[0]==v&&deg[f[1]]&1||f[1]==v&&deg[f[0]]&1);
				else {
					adj[f[0]].pb(f[1]);
					adj[f[1]].pb(f[0]);
				}
			}
			//test graph connectivity
			vt<vt<int>> r=comp(v);
			FOR(n)
				adj[i].clear();
			memset(vis, 0, n);
			if(sz(r)<2)
				printsol(u, v);
		} else {
			//remove all odd edges
			EACH(f, e) {
				if(f[0]==v&&deg[f[1]]&1||f[1]==v&&deg[f[0]]&1);
				else {
					adj[f[0]].pb(f[1]);
					adj[f[1]].pb(f[0]);
				}
			}
			//test graph connectivity
			vt<vt<int>> r=comp(v);
			FOR(n)
				adj[i].clear();
			memset(vis, 0, n);
			//if connected, yay
			if(sz(r)<2)
				printsol(v, v);
			//if more then 2 components, bad
			if(sz(r)>2)
				continue;
			//find odd edge which connects components to find u
			memset(l, -1, 4*n);
			FOR(k, 2)
				EACH(u, r[k])
					l[u]=k;
			EACH(o, odd)
				if(~l[o]&&l[o]!=l[v])
					printsol(o, v);
		}
	}
	print(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//read(t);
	FOR(t) {
		//write("Case #", i+1, ": ");
		solve();
	}
}