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
int n, m, eu[mxN], ev[mxN], ew[mxN], ans[mxN], d1[mxN], d2[mxN], ans1, stp[mxN];
vt<int> adj[mxN], adj1[mxN], adj2[mxN];
bool ve[mxN];

void remcyc() {
	FOR(s, n) {
		//dbg(s);
		vt<int> st{s}, ste{-1};
		stp[s]=1;
		while(sz(st)) {
			int u=st.back();
			//dbg(u);
			if(stp[u]&&stp[u]^sz(st)) {
				//dbg("removing cycle");
				st.pop_back();
				while(stp[u]) {
					stp[st.back()]=0;
					ans[ste.back()]=st.back()==eu[ste.back()]?1:2;
					dbg("removed", ste.back());
					st.pop_back();
					ste.pop_back();
				}
				st.pb(u);
			}
			stp[u]=sz(st);
			while(sz(adj[u])&&ve[adj[u].back()])
				adj[u].pop_back();
			if(!sz(adj[u])) {
				stp[u]=0;
				st.pop_back();
				ste.pop_back();
				continue;
			}
			int e=adj[u].back();
			//dbg(e);
			ve[e]=1;
			st.pb(eu[e]^ev[e]^u);
			ste.pb(e);
		}
	}
	memset(ve, 0, m);
}

void path2(int u, int d);

void path1(int u, int d) {
	if(d1[u]&1) {
		while(ve[adj1[u].back()])
			adj1[u].pop_back();
		int e=adj1[u].back();
		ve[e]=1;
		ans[e]=eu[e]==u?d:3^d;
		int v=eu[e]^ev[e]^u;
		--d1[u];
		--d1[v];
		path1(v, d);
	} else if(d2[u]&1)
		path2(u, d);
}

void path2(int u, int d) {
	dbg("path2", u);
	if(d2[u]&1) {
		while(ve[adj2[u].back()])
			adj2[u].pop_back();
		int e=adj2[u].back();
		ve[e]=1;
		ans[e]=eu[e]==u?d:3^d;
		int v=eu[e]^ev[e]^u;
		--d2[u];
		--d2[v];
		path2(v, d);
	} else if(d1[u]&1)
		path1(u, d);
}

void solve() {
	read(n, m);
	FOR(m) {
		read(eu[i], ev[i], ew[i]), --eu[i], --ev[i];
		if(ew[i]<2) {
			adj[eu[i]].pb(i);
			adj[ev[i]].pb(i);
		}
	}
	remcyc();
	//dbg("hi1");
	FOR(m) {
		if(ew[i]>1) {
			adj[eu[i]].pb(i);
			adj[ev[i]].pb(i);
		}
	}
	remcyc();
	FOR(m) {
		if(ans[i])
			continue;
		if(ew[i]<2) {
			adj1[eu[i]].pb(i);
			adj1[ev[i]].pb(i);
			++d1[eu[i]];
			++d1[ev[i]];
		} else {
			adj2[eu[i]].pb(i);
			adj2[ev[i]].pb(i);
			++d2[eu[i]];
			++d2[ev[i]];
		}
	}
	//dbg("hi2");
	FOR(n)
		if(d1[i]&1)
			++ans1;
	FOR(n) {
		if(d1[i]&1) {
			path1(i, 1);
			if(d2[i]&1)
				path2(i, 2);
		}
	}
	FOR(n)
		if(d2[i]&1)
			path2(i, 1);
	print(ans1);
	FOR(m)
		write(ans[i]);
	print();
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