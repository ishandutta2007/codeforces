#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset
#define int long long
using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
#undef int

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define int long long

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ll> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {(ll) n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

int multiplicity(ll x, int a){
    int ans = 0;
    while(x % a == 0){
        x /= a;
        ans++;
    }
    return ans;
}

void solve(){
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    if(y % x != 0){
        cout << 0 << endl;
        return;
    }
    
    vll xf = factor(x);
    vll yf = factor(y);
    debug(xf, yf);
    set<int> fs;
    for(int i : xf) fs.insert(i);
    for(int i : yf) fs.insert(i);
    vi fac(fs.begin(), fs.end());
    debug(fac);

    vi factors, a, b;
    for(int i : fac){
        if(multiplicity(x, i) != multiplicity(y, i)){
            factors.push_back(i);
            a.push_back(multiplicity(x, i));
            b.push_back(multiplicity(y, i));
        }
    }
    int m = factors.size();
    debug(factors, a, b, m);

    vi acnt(1<<m), bcnt(1<<m);
    for(int i = 0; i < n; i++){
        int am = 0, bm = 0;
        for(int j = 0; j < m; j++){
            int mul = multiplicity(v[i], factors[j]);
            if(mul > a[j]) am |= (1<<j);
            if(mul < b[j]) bm |= (1<<j);
        }
        if(v[i] % x == 0){
            acnt[am]++;
        }
        if(y % v[i] == 0){
            bcnt[bm]++;
        }
    }
    
    debug(acnt, bcnt);

    // sos on bcnt
    for(int b = 0; b < m; b++){
        for(int i = 0; i < (1<<m); i++){
            if((i>>b)&1){
                bcnt[i] += bcnt[i^(1<<b)];
            }
        }
    }

    ll ans = 0;
    int toggle_mask = (1<<m)-1;
    for(int i = 0; i < (1<<m); i++){
        ans += (ll) acnt[i] * bcnt[toggle_mask ^ i];
    }
    cout << ans << endl;
}
#undef int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}