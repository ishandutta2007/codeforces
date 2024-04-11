//     
//    Zhikun Wang (nocriz)
//    $_DATE

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

const int MOD = 998244353;
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

int N,n;
int exist[1000010];
int cnt[2000010],val[2000010];
void build(int l,int r,int id){
	if(l == r){
		cnt[id] = exist[r];val[id] = exist[r]?r:0;
		return;
	}
	int m = (l+r)/2;
	build(l,m,id*2);
	build(m+1,r,id*2+1);
	cnt[id] = cnt[id*2]+cnt[id*2+1];
	val[id] = val[id*2]^val[id*2+1];
}
vi ans[2000010],mx[2000010],mi[2000010];
void dfs(int l,int r,int id = 1){
	ans[id].resize(r-l+1,100000000);
	mx[id].resize(r-l+1,0);
	mi[id].resize(r-l+1,100000000);
	if(l == r){
		mx[id].resize(1,0);
		mi[id][0] = 0;
		return;
	}
	int m = (l+r)/2;
	if(cnt[id*2])dfs(l,m,id*2);
	if(cnt[id*2+1])dfs(m+1,r,id*2+1);
	int clen = (r-l+1),hlen = clen/2;
	if(cnt[id*2]){
		F0R(i,(r-l)+1){
			ans[id][i] = min(ans[id][i],ans[id*2][i%hlen]);
			mx[id][i] = max(mx[id][i],mx[id*2][i%hlen]+((i>=hlen)?hlen:0));
			mi[id][i] = min(mi[id][i],mi[id*2][i%hlen]+((i>=hlen)?hlen:0));
		}
	}
	if(cnt[id*2+1]){
		F0R(i,(r-l)+1){
			ans[id][i] = min(ans[id][i],ans[id*2+1][i%hlen]);
			mx[id][i] = max(mx[id][i],mx[id*2+1][i%hlen]+((i<hlen)?hlen:0));
			mi[id][i] = min(mi[id][i],mi[id*2+1][i%hlen]+((i<hlen)?hlen:0));
		}
	}
	if(cnt[id*2] && cnt[id*2+1]){
		F0R(i,(r-l)+1){
			ans[id][i] = min(ans[id][i],abs(
				(mi[id*2+1][i%hlen]+((i<hlen)?hlen:0))-(mx[id*2][i%hlen]+((i>=hlen)?hlen:0))));
			ans[id][i] = min(ans[id][i],abs(
				(mi[id*2][i%hlen]+((i>=hlen)?hlen:0))-(mx[id*2+1][i%hlen]+((i<hlen)?hlen:0))));
		}
	}
}

int main() {
	re(n,N);
	N = 1<<N;
	F0R(i,n){
		ints(p);
		exist[p] = 1;
	}
	build(0,N-1,1);
	dfs(0,N-1);
	each(ct,ans[1]){
		pr(ct,' ');
	}
	pr('\n');
	return 0;
}