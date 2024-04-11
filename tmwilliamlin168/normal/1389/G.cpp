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

const int mxN=3e5;
int n, m, k, sp2[mxN], sps[mxN], eu[mxN], ev[mxN], dt=1, tin[mxN], low[mxN], who[mxN], st[mxN+1], sth, bccI;
ll c[mxN], ew[mxN], c2[mxN], ans[mxN], dp[mxN];
vector<int> adj1[mxN], adj2[mxN];
bool sp[mxN];

void dfs1(int u=0, int p=-1) {
	tin[u]=low[u]=dt++;
	st[sth++]=u;
	for(int e : adj1[u]) {
		int v=u^eu[e]^ev[e];
		if(!tin[v]) {
			dfs1(v, e);
			low[u]=min(low[v], low[u]);
		} else if(e!=p)
			low[u]=min(tin[v], low[u]);
	}
	if(low[u]==tin[u]) {
		st[sth]=-1;
		while(st[sth]!=u) {
			who[st[--sth]]=bccI;
			c2[bccI]+=c[st[sth]];
			sp2[bccI]+=sp[st[sth]];
		}
		++bccI;
	}
}

void dfs2(int u=0, int pe=-1) {
	sps[u]=sp2[u];
	dp[u]=c2[u];
	for(int e : adj2[u]) {
		if(e==pe)
			continue;
		int v=u^eu[e]^ev[e];
		dfs2(v, e);
		sps[u]+=sps[v];
		if(sps[v]&&sps[v]<k)
			dp[u]+=max(0ll, dp[v]-ew[e]);
		else
			dp[u]+=dp[v];
	}
}

void dfs3(int u=0, int pe=-1, ll pdp=0) {
	ans[u]=dp[u]+(~pe?((k-sps[u])&&(k-sps[u])<k?max(0ll, pdp-ew[pe]):pdp):0);
	for(int e : adj2[u]) {
		if(e==pe)
			continue;
		int v=u^eu[e]^ev[e];
		dfs3(v, e, ans[u]-(sps[v]&&sps[v]<k?max(0ll, dp[v]-ew[e]):dp[v]));
	}
}

void solve() {
	read(n, m, k);
	FOR(k) {
		int v;
		read(v), --v;
		sp[v]=1;
	}
	FOR(n)
		read(c[i]);
	FOR(m)
		read(ew[i]);
	FOR(m) {
		read(eu[i], ev[i]), --eu[i], --ev[i];
		adj1[eu[i]].pb(i);
		adj1[ev[i]].pb(i);
	}
	dfs1();
	FOR(m) {
		eu[i]=who[eu[i]];
		ev[i]=who[ev[i]];
		if(eu[i]^ev[i]) {
			adj2[eu[i]].pb(i);
			adj2[ev[i]].pb(i);
		}
	}
	dfs2();
	dfs3();
	FOR(n)
		write(ans[who[i]], ' ');
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