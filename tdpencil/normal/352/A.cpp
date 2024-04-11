#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(), x.end()
#define gen generate
#define ar array
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define ub upper_bound
#define lb lower_bound
#define V vector
#define nl '\n'
#define vi V<int>
#define pi pair<int, int>
#define pii pair<int, int>
#define vl V<ll>
#define vpi V<pi>
#define vpl V<pl>
#define trav(x, y) for (auto &x : y)
#define vb V<bool>
#define bs bitset
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define F0R(i, N) rep(i, 0, N)
#define P pair

const int mxN = 1e5, M = 998244353, mod = 1e9 + 7;
template <typename K>
using pq = priority_queue<K>;
template <typename K>
using pqg = priority_queue<K, V<K>, greater<K>>;
template <typename K>
using dq = deque<K>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
    template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
    template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
inline ll nxt()
{
    ll x;
    cin >> x;
    return x;
}
inline string read()
{
    string a;
    cin >> a;
    return a;
}
    template <class T>
bool umax(T &x, T y)
{
    if (x < y)
    {
        x = y;
        return 1;
    }
    return 0;
}
template <class T>
bool umin(T &x, T y) {
    if (x > y)
    {
        x = y;
        return 1;
    }
    return 0;
}



#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
#define vt V

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


void solve(int test_case = 0) {
    int n;
    cin >> n;
    ar<int, 2> c;
    c.fill(0);

    for(int i = 0; i < n; i++) {
        int num = nxt();
        if(num == 5)
            c[1]++;
        else
            c[0]++;
    }
    int biggest_five_group = 0;
    rep(n_fives, 0, c[1]+1) {
        if(5 * n_fives % 9 == 0) {
            biggest_five_group = n_fives;
        } 
    }
    if(biggest_five_group > 0 && c[0]) {
        rep(i,0,biggest_five_group)
            write(5);
        rep(i,0,c[0])
            write(0);
    } else if(c[0]) {
        write(0);
    }else  print(-1);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    //cin >> t; 
    for (int nt = 0, i; nt < t; nt++)
    {
        solve(nt);
        ++i;
    }
}