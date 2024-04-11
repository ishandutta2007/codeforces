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

const int mxN=3e5, M=998244353;
const ll M2=(ll)M*M;
int n, m, l[mxN], r[mxN], cs[mxN+1], id[mxN], adj2[21], d[22][mxN+1];
vt<int> adj[mxN], cv;
vt<ll> p[mxN+1];
bool vis[mxN];
ll iv[mxN+1], f1[mxN+1], f2[mxN+1];

void dfs(int u) {
	vis[u]=1;
	cv.pb(u);
	EACH(v, adj[u])
		if(!vis[v])
			dfs(v);
}

vt<ll> mult(vt<ll> a, vt<ll> b) {
	vt<ll> c(sz(a)+sz(b)-1);
	FOR(sz(a)) {
		FOR(j, sz(b)) {
			c[i+j]+=a[i]*b[j];
			if(c[i+j]>=M2)
				c[i+j]-=M2;
		}
	}
	EACH(d, c)
		d%=M;
	return c;
}

void solve() {
	read(n, m);
	FOR(n)
		read(l[i], r[i]);
	FOR(m) {
		int a, b;
		read(a, b), --a, --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	FOR(n)
		p[i+1]={1};
	FOR(n) {
		if(vis[i])
			continue;
		dfs(i);
		if(sz(cv)<2) {
			++cs[r[i]];
			--cs[l[i]-1];
		} else {
			FOR(sz(cv))
				id[cv[i]]=i;
			EACH(u, cv)
				EACH(v, adj[u])
					adj2[id[u]]|=1<<id[v];
			FOR(1<<sz(cv)) {
				int cl=1, cr=n;
				FOR(j, sz(cv)) {
					if(i>>j&1) {
						umax(cl, l[cv[j]]);
						umin(cr, r[cv[j]]);
						if(adj2[j]&i)
							cr=0;
					}
				}
				if(cl<=cr) {
					++d[__builtin_popcount(i)][cr];
					--d[__builtin_popcount(i)][cl-1];
				}
			}
			FOR(sz(cv)+1)
				FOR(j, n, 1, -1)
					d[i][j-1]+=d[i][j];
			FOR(j, 1, n+1) {
				vt<ll> q;
				FOR(sz(cv)+1)
					q.pb(d[i][j]);
				p[j]=mult(p[j], q);
			}
			FOR(sz(cv)+1)
				memset(d[i], 0, sizeof(d[i]));
			memset(adj2, 0, sizeof(adj2));
		}
		cv.clear();
	}
	FOR(i, n, 1, -1)
		cs[i-1]+=cs[i];
	iv[1]=1;
	FOR(i, 2, n+1)
		iv[i]=M-M/i*iv[M%i]%M;
	f1[0]=f2[0]=1;
	FOR(i, 1, n+1) {
		f1[i]=f1[i-1]*i%M;
		f2[i]=f2[i-1]*iv[i]%M;
	}
	ll ans=0;
	FOR(i, 1, n+1)
		FOR(j, sz(p[i]))
			if(j<=i&&i-j<=cs[i])
				ans+=p[i][j]*f1[cs[i]]%M*f2[i-j]%M*f2[cs[i]-(i-j)]%M;
	print(ans%M);
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