#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

struct Random_Number_Generator{
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator () (int64_t l, int64_t r){
        uniform_int_distribution<int64_t> dist(l, r-1);
        return dist(mt);
    }

    int64_t operator () (int64_t r){ 
        return (*this)(0, r);
    }
};

using ull = unsigned long long;

struct Rolling_Hash{
    const ull mod = (1ull<<61)-1;

    ull calc_mod(ull x) const{
        ull ret = (x>>61) + (x&mod);
        return ret - (ret >= mod? mod : 0);
    }

    ull mul(ull x, ull y) const{
        x = calc_mod(x), y = calc_mod(y);
        ull x1 = x>>31, x2 = x&((1ull<<31)-1), y1 = y>>31, y2 = y&((1ull<<31)-1);
        ull z = x1*y2 + x2*y1, z1 = z>>30, z2 = z&((1ull<<30)-1);
        return calc_mod(x1*y1*2 + x2*y2 + z1 + (z2<<31));
    }

    ull pow(ull x, ull n) const{
        ull ret = 1;
        for(; n > 0; n >>= 1, x = mul(x, x)){
            if(n&1) ret = mul(ret, x);
        }
        return ret;
    }

    ull base; //
    vector<ull> hashed, pw;

    void set_base(){ //
        Random_Number_Generator rnd;
        while(true){
            ull k = rnd(mod);
            if(gcd(mod-1, k) != 1) continue;
            base = pow(3, k);
            if(base < 256) continue;
            break;
        }
    }

    Rolling_Hash(const string &s){
        set_base();
        int n = s.size();
        hashed.resize(n+1), pw.resize(n+1);
        hashed[0] = 0, pw[0] = 1;
        for(int i = 0; i < n; i++){
            pw[i+1] = mul(pw[i], base);
            hashed[i+1] = mul(hashed[i], base) + s[i];
            if(hashed[i+1] >= mod) hashed[i+1] -= mod;
        }
    }

    ull query(int l, int r) const{
        ull ret = hashed[r] + mod - mul(hashed[l], pw[r-l]);
        return ret - (ret >= mod? mod : 0);
    }

    ull get_hash(const string &s) const{
        ull ret = 0;
        for(int i = 0; i < (int)s.size(); i++){
            ret = mul(ret, base) + s[i];
            if(ret >= mod) ret -= mod;
        }
        return ret;
    }
};

template<typename T>
struct Array_Hash{
    const ull mod = (1ull<<61)-1; 

    ull calc_mod(ull x) const{
        ull ret = (x>>61) + (x&mod);
        return ret - (ret >= mod? mod : 0);
    }

    ull mul(ull x, ull y) const{
        x = calc_mod(x), y = calc_mod(y);
        ull x1 = x>>31, x2 = x&((1ull<<31)-1), y1 = y>>31, y2 = y&((1ull<<31)-1);
        ull z = x1*y2 + x2*y1, z1 = z>>30, z2 = z&((1ull<<30)-1);
        return calc_mod(x1*y1*2 + x2*y2 + z1 + (z2<<31));
    }

    ull pow(ull x, ull n) const{
        ull ret = 1;
        for(; n > 0; n >>= 1, x = mul(x, x)){
            if(n&1) ret = mul(ret, x);
        }
        return ret;
    }

    ull base;
    vector<ull> pw;

    void set_base(T m){
        Random_Number_Generator rnd;
        while(true){
            ull k = rnd(mod);
            if(gcd(mod-1, k) != 1) continue;
            base = pow(3, k);
            if(base <= ull(m)) continue;
            break;
        }
    }

    Array_Hash(int n, T m){ //
        set_base(m);
        pw.resize(n+1);
        pw[0] = 1;
        for(int i = 0; i < n; i++){
            pw[i+1] = mul(pw[i], base);
        }
    }

    ull get_hash(const vector<T> &v) const{
        ull ret = 0;
        for(int i = 0; i < (int)v.size(); i++){
            ret += mul(v[i], pw[i]);
            if(ret >= mod) ret -= mod;
        }
        return ret;
    }
};

int main(){
    int N, M; cin >> N >> M;

    vector<vector<int>> a(N, vector<int>(M)), b(N, vector<int>(M));

    rep(i, N){
        rep(j, M) cin >> a[i][j];
    }
    rep(i, N){
        rep(j, M) cin >> b[i][j];
    }

    Array_Hash<int> ah(M, N);
    map<ull, vector<int>> mp;
    map<ull, int> ptr;

    rep(i, N){
        mp[ah.get_hash(a[i])].eb(i);
    }

    vector<int> res(N);
    rep(i, N){
        ull h = ah.get_hash(b[i]);
        int &p = ptr[h];
        if(p >= sz(mp[h])) {cout << "-1\n"; return 0;}

        res[i] = mp[h][p++];
    }

    //rep(i, N) cout << res[i] << ' '; cout << '\n';

    vector<vector<int>> c(N-1, vector<int>(M));
    vector<int> cnt(M, 0); //-1

    rep(i, N-1){
        int u = res[i], v = res[i+1];
        rep(j, M){
            if(a[u][j] < a[v][j]) c[i][j] = 1;
            else if(a[u][j] == a[v][j]) c[i][j] = 0;
            else c[i][j] = -1, cnt[j]++;
        }
    }

    vector<bool> ok(N-1, false);

    queue<int> que;
    rep(i, M){
        if(cnt[i] == 0) que.emplace(i);
    }

    vector<int> ans;

    while(!que.empty()){
        int j = que.front(); que.pop();

        ans.eb(j);
        rep(i, N-1){
            if(ok[i] == true || c[i][j] != 1) continue;

            ok[i] = true;
            rep(k, M){
                if(c[i][k] != -1) continue;
                if(--cnt[k] == 0) que.emplace(k);
            }
        }
    }

    rep(i, N-1){
        if(!ok[i] && res[i] > res[i+1]) {cout << "-1\n"; return 0;}
    }

    reverse(all(ans));

    cout << sz(ans) << '\n';
    rep(i, sz(ans)){
        cout << ans[i]+1 << (i == sz(ans)-1? '\n' : ' ');
    }
}