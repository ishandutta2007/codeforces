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

using vb = vector<bool>;
using vvb = vector<vb>;

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

    bool sqrt_exists() const;
    ModInt sqrt() const;
};
template<uint M> ostream& operator<<(ostream &os, ModInt<M> x) { return os << x.val(); }
template<uint M> istream& operator>>(istream &is, ModInt<M> &x) { ll p; is >> p; x = ModInt<M>(p); return is; }

const uint MOD = 998244353;
using mint = ModInt<MOD>;

using cnum = mint;
const int N = 2e5 + 20;
cnum fact[N];
cnum inv_fact[N];
void precomp(){ // don't forget to call precomp()!
    fact[0] = mint(1);
    for(int i = 1; i < N; i++){
        fact[i] = fact[i-1] * i;
    }
    for(int i = 0; i < N; i++){
        inv_fact[i] = fact[i].inv();
    }
}

cnum ncr(ll n, ll r){
    assert(n >= 0);
    if(r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] * inv_fact[n-r];
}

struct Point{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point() : x(-1), y(-1) {}
};

ostream& operator<<(ostream &os, const Point &p){ return os << '{' << p.x << ',' << p.y << '}'; }

using P = Point;

int d(P &a, P &b){
    return abs(a.x-b.x) + abs(a.y - b.y);
}

void solve(){
    int n;
    cin >> n;
    vector<Point> pts(n);
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    debug(pts);

    vvb good(n, vb(n, 1));
    for(int i = 0; i < n; i++){
        int min_dist = 1e9;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            min_dist = min(min_dist, d(pts[i], pts[j]));
        }

        for(int j = 0; j < n; j++){
            if(i != j && d(pts[i], pts[j]) != min_dist){
                good[i][j] = 0;
                good[j][i] = 0;
            }
        }
    }
    debug(good);

    vi clique_size;
    vi vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        vi clique;
        clique.push_back(i);
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v = 0; v < n; v++){
                if(!vis[v] && good[u][v]){
                    q.push(v);
                    vis[v] = 1;
                    clique.push_back(v);
                }
            }
        }
        debug(clique);

        // check if it really is a clique
        bool ok = clique.size() <= 4;
        if(ok && clique.size() > 1){
            int target = d(pts[clique[0]], pts[clique[1]]);
            for(int i = 0; i < clique.size(); i++){
                for(int j = i+1; j < clique.size(); j++){
                    if(d(pts[clique[i]], pts[clique[j]]) != target){
                        ok = false;
                    }
                }
            }
            for(int i = 0; i < clique.size(); i++){
                for(int j = 0; j < n; j++){
                    if(find(clique.begin(), clique.end(), j) == clique.end()){
                        if(d(pts[clique[i]], pts[j]) <= target){
                            ok = false;
                        }
                    }
                }
            }
        }

        if(ok){
            clique_size.push_back(clique.size());
        }else{
            for(int i : clique){
                clique_size.push_back(1);
            }
        }
    }
    debug(clique_size);

    vector<vector<mint>> dp(clique_size.size() + 1, vector<mint>(n+1)); // (# elements, # colors left)
    dp[0][n] = 1;
    for(int i = 0; i < clique_size.size(); i++){
        // keep clique
        for(int j = 1; j <= n; j++){
            dp[i+1][j-1] += dp[i][j] * j;
        }

        if(clique_size[i] > 1){
            // break clique
            for(int j = clique_size[i]; j <= n; j++){
                dp[i+1][j-clique_size[i]] += dp[i][j] * fact[j] / fact[j-clique_size[i]];
            }
        }
    }
    mint ans = 0;
    for(int i = 0; i <= n; i++){
        ans += dp[clique_size.size()][i];
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    solve();
    return 0;
}