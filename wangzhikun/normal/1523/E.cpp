//     
//    Zhikun Wang (nocriz)
//    Sat Jul 10 21:23:46 2021

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long; using db = long double; using str = string;
using pi = pair<int,int>; using pl = pair<ll,ll>; using pd = pair<db,db>;
using vi = vector<int>; using vb = vector<bool>; using vl = vector<ll>;
using vd = vector<db>; using vs = vector<str>;
using vpi = vector<pi>; using vpl = vector<pl>; using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>;  tcT, size_t SZ> using AR = array<T,SZ>; tcT> using PR = pair<T,T>;

#define mp make_pair 
#define f first
#define s second
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define lb lower_bound
#define ub upper_bound

tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
tcT> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
tcT> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
tcTU> T fstTrue(T lo, T hi, U f) { hi ++; assert(lo <= hi); while (lo < hi) { T mid = lo+(hi-lo)/2; f(mid) ? hi = mid : lo = mid+1; } return lo; }
tcTU> T lstTrue(T lo, T hi, U f) { lo --; assert(lo <= hi); while (lo < hi) { T mid = lo+(hi-lo+1)/2; f(mid) ? lo = mid : hi = mid-1; } return lo; }
tcT> void remDup(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { auto it = t.find(u); assert(it != end(t)); t.erase(it); } 
#define tcTUU tcT, class ...U
inline namespace Helpers { tcT, class = void> struct is_iterable : false_type {}; tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>())) > > : true_type {}; tcT> constexpr bool is_iterable_v = is_iterable<T>::value; tcT, class = void> struct is_readable : false_type {}; tcT> struct is_readable<T, typename std::enable_if_t< is_same_v<decltype(cin >> declval<T&>()), istream&> > > : true_type {}; tcT> constexpr bool is_readable_v = is_readable<T>::value; tcT, class = void> struct is_printable : false_type {}; tcT> struct is_printable<T, typename std::enable_if_t< is_same_v<decltype(cout << declval<T>()), ostream&> > > : true_type {}; tcT> constexpr bool is_printable_v = is_printable<T>::value;}
inline namespace Input { tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>; tcTUU> void re(T& t, U&... u); tcTU> void re(pair<T,U>& p); tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); tcTU> void re(pair<T,U>& p) { re(p.f,p.s); } tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) { each(x,i) re(x); } tcTUU> void re(T& t, U&... u) { re(t); re(u...); }}
inline namespace ToString {  tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;  tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {   stringstream ss; ss << fixed << setprecision(15) << v;   return ss.str(); }  tcT> str bit_vec(T t) {   str res = "{"; F0R(i,sz(t)) res += ts(t[i]);   res += "}"; return res; }  str ts(V<bool> v) { return bit_vec(v); }  template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); }   tcTU> str ts(pair<T,U> p);  tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v);   tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }  tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {   bool fst = 1; str res = "";   for (const auto& x: v) {    if (!fst) res += sep;    fst = 0; res += ts(x);   }   return res;  }  tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {   return "{"+ts_sep(v,", ")+"}"; }  template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type     ts_lev(const T& v) { return {ts(v)}; }  template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type     ts_lev(const T& v) {   if (lev == 0 || !sz(v)) return {ts(v)};   vs res;   for (const auto& t: v) {    if (sz(res)) res.bk += ",";    vs tmp = ts_lev<lev-1>(t);    res.ins(end(res),all(tmp));   }   F0R(i,sz(res)) {    str bef = " "; if (i == 0) bef = "{";    res[i] = bef+res[i];   }   res.bk += "}";   return res;  } }
inline namespace Output { template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); } template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); } template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } void ps() { cout << "\n"; } template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } template<class ...T> void dbg_out(const T&... t) { pr_sep(cerr," | ",t...); cerr << endl; }void loc_info(int line, str names) { cerr << "Line(" << line << ") -> [" << names << "]: "; } template<int lev, class T> void dbgl_out(const T& t) { cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; } }
#ifdef LOCAL
	#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
	#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
#else 
	#define dbg(...) 0
	#define dbgl(lev,x) 0
#endif
void decrement() {} // subtract one from each
tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);


template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = int((ll)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vmi fac(100010);

mi C(int a,int b){
	return fac[a]/fac[b]/fac[a-b];
}

int n,k;

int main() {
	cin.tie(0)->sync_with_stdio(0);
		int t; re(t);
	fac[0] = 1;
	FOR(i,1,100010)fac[i] = fac[i-1]*i;

	FOR(tc,1,t+1) {
		re(n,k);
		mi ans = 1;
		for(int i=1;n-(i-1)*(k-1)>=i;i++){
			ans+=C(n-(i-1)*(k-1),i)/C(n,i);
		}
		ps(ans.v);
	}
// END OF CODE
	return 0;
}