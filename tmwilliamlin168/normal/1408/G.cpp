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

const int mxN=1.5e3, M=998244353;
int n, a[mxN][mxN], p[mxN], r[mxN], s[mxN], s2[mxN], ec;
vt<int> adj[2*mxN];
bool t[2*mxN];
vt<ll> dp[2*mxN];

int find(int x) {
	return x^p[x]?p[x]=find(p[x]):x;
}

bool join(int x, int y) {
	if((x=find(x))==(y=find(y)))
		return 0;
	dbg("j", x, y);
	adj[n+ec].pb(r[x]);
	adj[n+ec].pb(r[y]);
	p[x]=y;
	s[y]+=s[x];
	s2[y]+=s2[x];
	r[y]=n+ec;
	return 1;
}

void dfs(int u) {
	dbg("dfs ", u);
	dp[u]={u>=n};
	for(int v : adj[u]) {
		dfs(v);
		vt<ll> dp2(sz(dp[u])+sz(dp[v])-1);
		FOR(sz(dp[u]))
			FOR(j, sz(dp[v]))
				dp2[i+j]=(dp2[i+j]+dp[u][i]*dp[v][j])%M;
		dp[u]=dp2;
	}
	if(t[u]) {
		while(dp[u].size()<2)
			dp[u].pb(0);
		dp[u][1]=(dp[u][1]+1)%M;
	}
}

void solve() {
	read(n);
	vt<ar<int, 3>> b;
	FOR(n)
		FOR(j, n) {
			read(a[i][j]);
			if(i<j)
				b.pb({a[i][j], i, j});
		}
	sort(all(b));
	iota(p, p+n, 0);
	iota(r, r+n, 0);
	fill(s, s+n, 1);
	EACH(c, b) {
		if(join(c[1], c[2])) {
			//e[ec++]={c[1], c[2]};
			++ec;
		}
		c[1]=find(c[1]);
		++s2[c[1]];
		if(s2[c[1]]==s[c[1]]*(s[c[1]]-1)/2)
			t[r[c[1]]]=1;
	}
	FOR(n)
		t[i]=1;
	dfs(n+ec-1);
	dp[n+ec-1].erase(dp[n+ec-1].begin());
	print(dp[n+ec-1]);
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