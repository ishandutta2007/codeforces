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

struct {
	//CUSTOM
	struct d1 {
		//values for segment
		//int len=1;
		//ll sum;
		//ll mn;
		ll mx;
	};
	struct d2 {
		//values for update
		//bool res=0;
		ll add=0;
	};
	d1 d1d1(d1 a, d1 b) {
		//return a+b
		d1 c;
		//c.len=a.len+b.len;
		//c.sum=a.sum+b.sum;
		//c.mn=min(a.mn, b.mn);
		c.mx=max(a.mx, b.mx);
		return c;
	}
	void d1d2(d1& a, d2& b) {
		//a+=b
		//if(b.res) {
			//a.sum=0;
			//a.mn=0;
			//a.mx=0;
		//}
		//a.sum+=a.len*b.add;
		//a.mn+=b.add;
		a.mx+=b.add;
	}
	void d2d2(d2& a, d2& b) {
		//a+=b
		//if(b.res) {
			//a.res=1;
			//a.add=0;
		//}
		a.add+=b.add;
	}
	//convert to d1
	template<class T> d1 cd1(T& x) {
		d1 a;
		//a.sum=x;
		//a.mn=x;
		a.mx=x;
		return a;
	}
	//TEMPLATE
	int n;
	vt<d1> st;
	vt<d2> lz;
	template<class T> void bld(vt<T>& a, int i, int l2, int r2) {
		if(l2==r2) {
			st[i]=cd1(a[l2]);
			return;
		}
		int m2=(l2+r2)/2;
		bld(a, 2*i, l2, m2);
		bld(a, 2*i+1, m2+1, r2);
		st[i]=d1d1(st[2*i], st[2*i+1]);
	}
	template<class T> void bld(vt<T> a) {
		n=sz(a);
		vti(st, d1{}, 4*n);
		vti(lz, d2{}, 4*n);
		bld(a, 1, 0, n-1);
	}
	void app(int i, d2 &x) {
		d1d2(st[i], x);
		d2d2(lz[i], x);
	}
	void psh(int i) {
		app(2*i, lz[i]);
		app(2*i+1, lz[i]);
		lz[i]={};
	}
	template<class T> void set(int l1, T& x, int i, int l2, int r2) {
		if(l2==r2) {
			st[i]=cd1(x);
			return;
		}
		int m2=(l2+r2)/2;
		psh(i);
		if(l1<=m2)
			set(l1, x, 2*i, l2, m2);
		else
			set(l1, x, 2*i+1, m2+1, r2);
		st[i]=d1d1(st[2*i], st[2*i+1]);
	}
	template<class T> void set(int l1, T x) {
		set(l1, x, 1, 0, n-1);
	}
	void upd(int l1, int r1, d2& x, int i, int l2, int r2) {
		if(l1<=l2&&r2<=r1) {
			app(i, x);
			return;
		}
		int m2=(l2+r2)/2;
		psh(i);
		if(l1<=m2)
			upd(l1, r1, x, 2*i, l2, m2);
		if(m2<r1)
			upd(l1, r1, x, 2*i+1, m2+1, r2);
		st[i]=d1d1(st[2*i], st[2*i+1]);
	}
	void upd(int l1, int r1, d2 x) {
		upd(l1, r1, x, 1, 0, n-1);
	}
	d1 qry(int l1, int r1, int i, int l2, int r2) {
		if(l1<=l2&&r2<=r1)
			return st[i];
		int m2=(l2+r2)/2;
		psh(i);
		if(l1>m2)
			return qry(l1, r1, 2*i+1, m2+1, r2);
		if(r1<=m2)
			return qry(l1, r1, 2*i, l2, m2);
		return d1d1(qry(l1, r1, 2*i, l2, m2), qry(l1, r1, 2*i+1, m2+1, r2));
	}
	d1 qry(int l1, int r1) {
		return qry(l1, r1, 1, 0, n-1);
	}
} st[2];

const int mxN=2e5;
int n;
ar<int, 3> a[mxN];

void solve() {
	read(n);
	vt<ar<int, 2>> v;
	FOR(n) {
		cin >> a[i][0] >> a[i][1] >> a[i][2], --a[i][2];
		v.pb({a[i][1], i});
	}
	sort(all(v));
	FOR(n) {
		a[i][0]=lower_bound(all(v), ar<int, 2>{a[i][0]})-v.begin();
		a[i][1]=lower_bound(all(v), ar<int, 2>{a[i][1], i})-v.begin();
	}
	sort(a, a+n, [](const ar<int, 3> &a, const ar<int, 3> &b) {
		return a[1]<b[1];
	});
	vt<int> b(n+1);
	st[0].bld(b);
	st[1].bld(b);
	FOR(n) {
		int t=a[i][2];
		st[t^1].upd(0, a[i][0], {1});
		st[t].upd(a[i][1]+1, a[i][1]+1, {st[t^1].qry(0, n).mx});
	}
	print(max(st[0].qry(0, n).mx, st[1].qry(0, n).mx));
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