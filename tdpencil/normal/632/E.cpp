//fast
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define nl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define trav(x,y) for(auto &x:y)
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define P pair
int n, m, k;
const int mxN=1e6,M=998244353,mod=1e9+7;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
const ll MOD = 1e9+7;
int v;
set<int> f;
multiset<int> maxes;
typedef complex<double> C;
typedef vector<double> vd;
typedef complex<double> base;
void fft(vector<base> &a, bool inv){
    int n = sz(a), j = 0;
    vector<base> roots(n/2);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit){
            j -= bit;
            bit >>=1;
        }
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang =2 * acos(-1) / n * (inv ? -1:1);
    for(int i=0; i<n/2; i++){
        roots[i] = base(cos(ang * i), sin(ang * i));
    }
    for(int i=2; i<=n; i<<=1){
        int step = n / i;
        for(int j=0; j<n; j+=i){
            for(int k=0; k<i/2; k++){
                base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
                a[j+k] = u+v;
                a[j+k+i/2] = u-v;
            }
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w) {
    int n =2; while(n < sz(v)+sz(w)) n <<=1;
    vector<base> v1(n), v2(n), r1(n), r2(n);
    for(int i=0; i<sz(v); i++){
        v1[i] = base(v[i] >> 15, v[i] & 32767);
    }
    for(int i=0; i<sz(w); i++){
        v2[i] = base(w[i] >> 15, w[i] & 32767);
    }
    fft(v1,0);
    fft(v2,0);
    for(int i=0; i<n; i++){
        int j = (i ? (n - i) : i);
        base ans1 = (v1[i] + conj(v1[j])) * base(0.5,0);
        base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
        base ans3 = (v2[i] + conj(v2[j])) * base(0.5,0);
        base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
        r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0,1);
        r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0,1);
    }
    fft(r1,1);fft(r2,1);
    vector<ll> ret(n);
    for(int i=0; i<n; i++){
        ll av = (ll)round(r1[i].real());
        ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
        ll cv = (ll)round(r2[i].imag());
        av %= MOD, bv %= MOD, cv %= MOD;
        ret[i] = (av << 30) + (bv << 15) + cv;
        ret[i] %= MOD;
        ret[i] += MOD;
        ret[i] %= MOD;
    }
    return ret;
}
vi a;
void solve(int test_case = 0) {
	int n, k;
	cin >> n >> k;

	// a^k
	a.resize(n);
	int mx=0;
	for(int i = 0; i < n; ++i)
		cin >> a[i],mx=max(mx,(int)a[i]);

	
	if(k == 1) {
		set<int> c;
		rep(i,0,n)
			c.insert(a[i]);
		trav(x,c) {
			cout << x << " ";
		}
		cout << nl;
		return;
	}
	vl r2;
	r2.resize(mx+1);
	for(int i = 0; i < n; ++i)
		r2[a[i]]=1;
	vl tmp(1,1);
	while(k) {
		if(k&1)
			tmp=multiply(tmp,r2);
		r2 = multiply(r2, r2);
		k >>= 1;
	}
	
	
	for(int i = 0; i < sz(tmp); i++) {
		if(tmp[i] != 0)
			cout << i << " ";
	}
	return;
	
}


int main()
{
	//setup();
	cin.tie(0)->sync_with_stdio(0);
	//precalc();
	int T = 1;
	// cin >> T;
	for(int nt = 0, i; nt < T; nt++) {
		solve(nt);
		++i;
	}
}