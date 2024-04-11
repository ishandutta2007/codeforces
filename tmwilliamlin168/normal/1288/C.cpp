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

ll inv(ll a, ll m) {
	return (a%=m)>1?(1-m*inv(m, a))/a+m:1;
}
template<int M> struct Mnt {
	int x;
	Mnt() {
		x=0;
	}
	Mnt(ll b) {
		if(b<-M||b>=M)
			b%=M;
		if(b<0)
			b+=M;
		x=b;
	}
	friend bool operator==(const Mnt& a, const Mnt& b) {
		return a.x==b.x;
	}
	friend bool operator!=(const Mnt& a, const Mnt& b) {
		return a.x^b.x;
	}
	friend bool operator<(const Mnt& a, const Mnt& b) {
		return a.x<b.x;
	}
	friend void read(Mnt& a) {
		ll x;
		read(x);
		a=Mnt(x);
	}
	friend string to_string(Mnt a) {
		return to_string(a.x);
	}
	Mnt& operator+=(const Mnt& a) {
		if((x+=a.x)>=M)
			x-=M;
		return *this;
	}
	Mnt& operator-=(const Mnt& a) {
		if((x-=a.x)<0)
			x+=M;
		return *this;
	}
	Mnt& operator*=(const Mnt& a) {
		x=(ll)x*a.x%M;
		return *this;
	}
	Mnt& operator/=(const Mnt& a) {
		return (*this)*=inv(a.x, M);
	}
	friend Mnt pm(Mnt a, ll p) {
		Mnt r=1;
		for (; p; p/=2, a*=a)
			if(p&1)
				r*=a;
		return r;
	}
	Mnt operator-() const {
		return Mnt(-x);
	}
	Mnt& operator++() {
		return *this+=1;
	}
	Mnt& operator--() {
		return *this-=1;
	}
	friend Mnt operator+(Mnt a, const Mnt& b) {
		return a+=b;
	}
	friend Mnt operator-(Mnt a, const Mnt& b) {
		return a-=b;
	}
	friend Mnt operator*(Mnt a, const Mnt& b) {
		return a*=b;
	}
	friend Mnt operator/(Mnt a, const Mnt& b) {
		return a/=b;
	}
};
template<int N, int M> struct combo {
	Mnt<M> iv[N+1], f1[N+1], f2[N+1];
	combo() {
		iv[1]=1;
		FOR(i, 2, N+1)
			iv[i]=-M/i*iv[M%i];
		f1[0]=f2[0]=1;
		FOR(i, 1, N+1) {
			f1[i]=f1[i-1]*i;
			f2[i]=f2[i-1]*iv[i];
		}
	}
	Mnt<M> inv2(int n) {
		return iv[n];
	}
	Mnt<M> fact(int n) {
		return f1[n];
	}
	Mnt<M> invfact(int n) {
		return f2[n];
	}
	Mnt<M> nck(int n, int k) {
		return f1[n]*f2[k]*f2[n-k];
	}
	Mnt<M> nck2(int n, int k) {
		umin(k, n-k);
		Mnt<M> r=f2[k];
		FOR(k)
			r*=n-i;
		return r;
	}
	vt<Mnt<M>> gp(int n, Mnt<M> b) {
		vt<Mnt<M>> v(n+1, 1);
		FOR(n)
			v[i+1]=v[i]*b;
		return v;
	}
};

const int M=1e9+7;
combo<200000, M> c;

void solve() {
	int n, m;
	read(n, m);
	print(c.nck(2*m+n-1, 2*m));
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