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

// prime mods only, adapted from ACL
using uint = unsigned int;
using ull = unsigned long long;
template <uint MOD>
struct ModInt{
    uint _v;
    ModInt() : _v(0) {}
    ModInt(int val) {
        int x = val % (int) MOD;
        if(x < 0) x += MOD;
        _v = (uint) x;
    }
    ModInt(ll val){
        ll x = val % (ll) MOD;
        if(x < 0) x += MOD;
        _v = (uint) x;
    }
    ModInt(uint val) {
        _v = val % MOD;
    }
    ModInt(ull val) {
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
    ModInt operator-() const { return ModInt() - *this; }
    ModInt pow(ll n) const {
        assert(0 <= n);
        ModInt x = *this, r = 1;
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
template<uint M> ostream& operator<<(ostream &os, ModInt<M> x) { return os << x.val(); }
template<uint M> istream& operator>>(istream &is, ModInt<M> &x) { ll p; is >> p; x = ModInt<M>(p); return is; }

const uint MOD = 998244353;
using mint = ModInt<MOD>;

const int MAXN = 200005;
// const int MAXN = 10;

mint dp[MAXN][8][4][4][4]; // flags: x, y, x xor y match?; states for x^y, y^xy, xy^x
// vector<vector<string>> answers[MAXN][8][4][4][4]; // for debug

bool bit(int x, int b){
    return (x >> b) & 1;
}

int transition(int state, int x, int y, int z){
    if(state == 2) return 2;
    if(state == 3) return 3;
    int mask = (x << 2) | (y << 1) | z;
    if(state == 0){
        if(mask == 0 || mask == 6 || mask == 5) return 0;
        if(mask == 1 || mask == 2 || mask == 3 || mask == 7) return 2;
        return 1;
    }
    if(mask == 7 || mask == 2 || mask == 1) return 1;
    if(mask == 3) return 0;
    return 3;
}

int transitions[3][4];

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    // vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(8, vector<mint>(8)));
    dp[0][7][0][0][0] = 1;
    // answers[0][7][0][0][0].push_back(vector<string>(3, "")); // for debug
    for(int i = 1; i <= n; i++){
        for(int xb = 0; xb <= 1; xb++){
            for(int yb = 0; yb <= 1; yb++){
                for(int xyb = 0; xyb <= 1; xyb++){
                    for(int match = 0; match < 8; match++){
                        if(s[i-1] == '0' && ((xb == 1 && bit(match, 2))
                                        || (yb == 1 && bit(match, 1))
                                        || (xyb == 1 && bit(match, 0)))) continue;
                        // assert(!(s[i-1] == '0' && xb == 1 && (match & 1)));
                        int new_match = match;
                        if(s[i-1] == '1' && xb == 0) new_match &= (-1 ^ (1 << 2));
                        if(s[i-1] == '1' && yb == 0) new_match &= (-1 ^ (1 << 1));
                        if(s[i-1] == '1' && xyb == 0) new_match &= (-1 ^ 1);
                        int a = xb ^ yb;
                        int b = yb ^ xyb;
                        int c = xyb ^ xb;
                        for(int j = 0; j < 4; j++){
                            transitions[0][j] = transition(j, a, b, c);
                            transitions[1][j] = transition(j, b, c, a);
                            transitions[2][j] = transition(j, c, a, b);
                        }
                        for(int as = 0; as < 3; as++){
                            for(int bs = 0; bs < 3; bs++){
                                for(int cs = 0; cs < 3; cs++){
                                    dp[i][new_match][transitions[0][as]][transitions[1][bs]][transitions[2][cs]] += dp[i-1][match][as][bs][cs];
                                    // for(vector<string> a : answers[i-1][match][as][bs][cs]){
                                    //     vector<string> newa = a;
                                    //     newa[0] += ('0' + xb);
                                    //     newa[1] += ('0' + yb);
                                    //     newa[2] += ('0' + xyb);
                                    //     // if(newa[0].size() > 1) assert(newa[0][0] == '0' || newa[0][1] == '0');
                                    //     answers[i][new_match][transitions[0][as]][transitions[1][bs]][transitions[2][cs]].push_back(newa);
                                    // }
                                    // if(dp[i-1][match][as][bs][cs] != 0) {
                                    //     debug(i-1, match, as, bs, cs, dp[i-1][match][as][bs][cs], xb, yb, xyb);
                                    // }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    mint ans = 0;
    for(int match = 0; match < 8; match++){
        ans += dp[n][match][2][2][2];
        // for(vector<string> ans : answers[n][match][2][2][2]){
        //     debug(ans);
        // }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}