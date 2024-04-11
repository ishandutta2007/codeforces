#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

// prime mods only, source: ACL
using uint = unsigned int;
using ull = unsigned long long;
struct ModInt{
    uint _v, MOD;
    ModInt(uint MOD) : _v(0), MOD(MOD) {}
    ModInt(int val, uint MOD) : MOD(MOD) {
        int x = val % MOD;
        if(x < 0) x += MOD;
        _v = (uint) x;
    }
    ModInt(ll val, uint MOD) : MOD(MOD) {
        ll x = val % (ll) MOD;
        if(x < 0) x += MOD;
        _v = (uint) x;
    }
    ModInt(uint val, uint MOD) : MOD(MOD) {
        _v = val % MOD;
    }
    ModInt(ull val, uint MOD) : MOD(MOD) {
        _v = (uint) (val % MOD);
    }
    uint val(){ return _v; }
    ModInt& operator++(){
        _v++;
        if(_v == MOD) _v = 0;
        return *this;
    }
    ModInt& operator--(){
        if(_v == 0) _v = MOD;
        _v--;
        return *this;
    }
    ModInt operator++(int){
        ModInt result = *this;
        ++*this;
        return result;
    }
    ModInt& operator--(int){
        ModInt result = *this;
        --*this;
        return result;
    }
    ModInt& operator+=(const ModInt& rhs){
        _v += rhs._v;
        if (_v >= MOD) _v -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& rhs){
        _v -= rhs._v;
        if (_v >= MOD) _v += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& rhs){
        ull z = _v;
        z *= rhs._v;
        _v = (uint)(z % MOD);
        return *this;
    }
    ModInt& operator/=(const ModInt& rhs){
        return *this = *this * rhs.inv();
    }
    ModInt operator+() const { return *this; }
    ModInt operator-() const { return ModInt(MOD) - *this; }
    ModInt pow(ll n) const {
        assert(0 <= n);
        ModInt x = *this, r = ModInt(1, MOD);
        while(n){
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    ModInt inv() const {
        assert(_v);
        return pow(MOD - 2);
    }
    friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) += rhs;
    }
    friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) -= rhs;
    }
    friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) *= rhs;
    }
    friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) /= rhs;
    }
    friend bool operator==(const ModInt& lhs, const ModInt& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const ModInt& lhs, const ModInt& rhs) {
        return lhs._v != rhs._v;
    }
};
ostream& operator<<(ostream &os, ModInt x) { return os << x.val(); }
istream& operator>>(istream &is, ModInt &x) { ll p; is >> p; x = ModInt(p); return is; }
 
 
const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
 
static ull splitmix64(ull x) {
    x += FIXED_RANDOM;
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
 
const int NMODS = 2;
uint MODS[NMODS];

struct CombinedMint{
    vector<ModInt> vals;
 
    CombinedMint() {
        for(int i = 0; i < NMODS; i++){
            vals.push_back(ModInt(0, MODS[i]));
        }
    }
 
    CombinedMint(ll x) {
        for(int i = 0; i < NMODS; i++){
            vals.push_back(ModInt(x, MODS[i]));
        }
    }
 
    CombinedMint& operator++(){
        for(int i = 0; i < NMODS; i++) vals[i]++;
        return *this;
    }
    CombinedMint& operator--(){
        for(int i = 0; i < NMODS; i++) vals[i]--;
        return *this;
    }
    CombinedMint operator++(int){
        CombinedMint result = *this;
        for(int i = 0; i < NMODS; i++) vals[i]++;
        return result;
    }
    CombinedMint& operator--(int){
        CombinedMint result = *this;
        for(int i = 0; i < NMODS; i++) vals[i]--;
        return result;
    }
    CombinedMint& operator+=(const CombinedMint& rhs){
        for(int i = 0; i < NMODS; i++) vals[i] += rhs.vals[i];
        return *this;
    }
    CombinedMint& operator-=(const CombinedMint& rhs){
        for(int i = 0; i < NMODS; i++) vals[i] -= rhs.vals[i];
        return *this;
    }
    CombinedMint& operator*=(const CombinedMint& rhs){
        for(int i = 0; i < NMODS; i++) vals[i] *= rhs.vals[i];
        return *this;
    }
    CombinedMint& operator/=(const CombinedMint& rhs){
        for(int i = 0; i < NMODS; i++) vals[i] /= rhs.vals[i];
        return *this;
    }
    CombinedMint operator+() const { return *this; }
    CombinedMint operator-() const { return CombinedMint(0) - *this; }
    CombinedMint pow(ll n) const {
        CombinedMint x;
        for(int i = 0; i < NMODS; i++) x.vals[i] = vals[i].pow(n);
        return x;
    }
    CombinedMint inv() const {
        CombinedMint x;
        for(int i = 0; i < NMODS; i++) x.vals[i] = vals[i].inv();
        return x;
    }
    friend CombinedMint operator+(const CombinedMint& lhs, const CombinedMint& rhs) {
        return CombinedMint(lhs) += rhs;
    }
    friend CombinedMint operator-(const CombinedMint& lhs, const CombinedMint& rhs) {
        return CombinedMint(lhs) -= rhs;
    }
    friend CombinedMint operator*(const CombinedMint& lhs, const CombinedMint& rhs) {
        return CombinedMint(lhs) *= rhs;
    }
    friend CombinedMint operator/(const CombinedMint& lhs, const CombinedMint& rhs) {
        return CombinedMint(lhs) /= rhs;
    }
 
    ull hsh() const {
        ull ou = 0;
        for(ModInt mi : vals){
            ou = splitmix64(ou * 0x2938a4f184103fab ^ mi.val());
        }
        return ou;
    }
    friend bool operator==(const CombinedMint& lhs, const CombinedMint& rhs) {
        return lhs.hsh() == rhs.hsh();
    }
    friend bool operator!=(const CombinedMint& lhs, const CombinedMint& rhs) {
        return lhs.hsh() != rhs.hsh();
    }
};
ostream& operator<<(ostream &os, CombinedMint x) { return os << x.vals[0].val(); }
 
using H = CombinedMint;

const int MAX = 5e5 + 5;
H pow10[MAX];
H invpow10[MAX];

H substr_hsh(vector<H> &s, int start, int len){
    return (s[start + len] - s[start] * pow10[len]);
}

// lcp of two prefixes s[x:] and t[y:]
int lcp(vector<H> s, vector<H> t, int x, int y){
    int ans = 0;
    for(int add = (1<<19); add; add >>= 1){
        int mid = ans + add;
        if(x + mid >= s.size() || y + mid >= t.size()) continue;
        if(substr_hsh(s, x, mid) == substr_hsh(t, y, mid)){
            ans = mid;
        }
    }
    return ans;
    // return max(0, (int) min(s.size() - x - 1, t.size() - y - 1) / 2);
}

void output(int a, int b, int d){
    cout << a+1 << ' ' << b << '\n' << b+1 << ' ' << d << '\n';
    exit(0);
}

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

vi Z(string S) {
    vi z(sz(S));
    int l = -1, r = -1;
    rep(i,1,sz(S)) {
        z[i] = i >= r ? 0 : min(r - i, z[i - l]);
        while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int randbetween(int a, int b){
    return a + rng() % (b-a);
}

void solve(){
    // gen primes
    for(int i = 0; i < NMODS; i++){
        int x = 1;
        while(!isPrime(x)) x = randbetween(1e9, 2e9);
        MODS[i] = x;
    }

    debug("st");
    pow10[0] = H(1);
    invpow10[0] = H(1);
    for(int i = 1; i < MAX; i++){
        pow10[i] = pow10[i-1] * H(10);
        invpow10[i] = pow10[i].inv();
    }

    string s, x;
    cin >> s >> x;

    int n = s.size(), m = x.size();
    vector<H> prefs(n+1);
    prefs[0] = H(0);
    for(int i = 0; i < n; i++){
        prefs[i+1] = prefs[i] * H(10) + (s[i]-'0');
    }
    
    vector<H> prefx(m+1);
    prefx[0] = H(0);
    for(int i = 0; i < m; i++){
        prefx[i+1] = prefx[i] * H(10) + (x[i]-'0');
    }

    // debug(substr_hsh(prefs, 2, 3));
    // debug(lcp(prefs, prefx, 2, 4));

    vi z = Z(x + '$' + s);

    debug("start");

    for(int l = 0; l + m <= n; l++){
        if(l % 1000 == 0) debug(l);
        // int cp = lcp(prefs, prefx, l, 0);
        int cp = z[l+x.size()+1];
        int diff = l + cp;
        debug(l, cp, diff);

        if(s[diff] > x[cp] || cp == m) continue;

        int chk = m - cp; // or chk-1

        H cur = substr_hsh(prefs, l, m);

        // right
        if(l+m+chk <= n && prefx[m] == cur + substr_hsh(prefs, l+m, chk)){
            output(l, l+m, l+m+chk);
        }
        if(chk > 1 && l+m+chk-1 <= n && prefx[m] == cur + substr_hsh(prefs, l+m, chk-1)){
            output(l, l+m, l+m+chk-1);
        }

        // left
        if(l-chk >= 0 && prefx[m] == cur + substr_hsh(prefs, l-chk, chk)){
            output(l-chk, l, l+m);
        }
        if(chk > 1 && l-chk+1 >= 0 && prefx[m] == cur + substr_hsh(prefs, l-chk+1, chk-1)){
            output(l-chk+1, l, l+m);
        }
    }
    debug("done");

    // todo (m-1)+(m-1)
    if(m > 1){
        for(int i = 0; i+2*m-2 <= n; i++){
            if(prefx[m] == substr_hsh(prefs, i, m-1) + substr_hsh(prefs, i+m-1, m-1)){
                output(i, i+m-1, i+2*m-2);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    // string s = "234059827348780241734019284723475726394582345293857234059812349";
    // int n = s.size();
    // vector<H> prefs(n+1);
    // prefs[0] = H(0);
    // for(int i = 0; i < n; i++){
    //     prefs[i+1] = prefs[i] * H(10) + (s[i]-'0');
    // }
    // H x = 0;
    // for(int i = 0; i < 500000; i++){
    //     x += lcp(prefs, prefs, i%20, i%17);
    // }
    // cout << x << endl;
    return 0;
}