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

// fft implementation
const ll MOD = 998244353; // 2^23 * 119 + 1
const ll base = 1 << 20;
const ll root = 565042129; // primitive root of MOD = 3, root(2^23) = 3^119, root(2^20) = root(2^23)^(2^3)
// const ll base = 1 << 4;
// const ll root = 929031873;
// const ll inv2 = 499122177; // inverse of 2 mod MOD

const int MAXN = 3e5 + 10;
// const ll MAXN = 10;

vi factorial(2 * MAXN);
vi inv_factorial(2 * MAXN);


int ncr(int n, int r){
    return (int) (1LL * factorial[n] * (1LL * inv_factorial[r] * inv_factorial[n-r] % MOD) % MOD);
}

ll binexp(ll a, ll b, ll mod = MOD){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int inverse(int x){
    return binexp(x, MOD - 2);
}

void fft(vi &a, bool invert){
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    for(int len = 2; len <= n; len <<= 1){
        ll cur_root = root;
        ll cur_base = base;
        while(cur_base > len){
            cur_base >>= 1;
            cur_root = cur_root * cur_root % MOD;
        }
        if(invert){
            cur_root = inverse(cur_root);
        }
        for(int i = 0; i < n; i += len){
            ll cur_exp = 1;
            for(int j = 0; j < len / 2; j++){
                int u = a[i+j], v = (int) (1ll * a[i+j+len/2] * cur_exp % MOD);
                a[i+j] = u + v < MOD ? u + v : u + v - MOD;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
                cur_exp = cur_exp * cur_root % MOD;
            }
        }
    }

    if(invert){
        int n_inv = inverse(n);
        for(int i = 0; i < n; i++){
            a[i] = (int) (1ll * a[i] * n_inv % MOD);
        }
    }
}

// vll fft(vll a, bool invert){
//     int n = a.size();
//     if(n == 1){
//         return a;
//     }
//     ll cur_root = root;
//     ll cur_base = base;
//     while(cur_base > n){
//         cur_base >>= 1;
//         cur_root = cur_root * cur_root % MOD;
//     }
//     if(invert){
//         cur_root = inverse(cur_root);
//     }
//     vll even(n>>1), odd(n>>1);
//     for(int i = 0; 2*i < n; i++){
//         even[i] = a[2*i];
//         odd[i] = a[2*i+1];
//     }
//     debug(n, even, odd);

//     vll out_even = fft(even, invert);
//     vll out_odd = fft(odd, invert);
//     // debug("after fft", n);
//     debug(n, out_even, out_odd);

//     vll out(n);
//     ll cur_exp = 1;
//     for(int i = 0; i * 2 < n; i++){
//         debug(cur_exp);
//         out[i] = (out_even[i] + (cur_exp * out_odd[i] % MOD)) % MOD;
//         out[i + n/2] = ((out_even[i] - (cur_exp * out_odd[i] % MOD)) % MOD + MOD) % MOD;
//         if(invert){
//             out[i] = out[i] * inv2 % MOD;
//             out[i + n/2] = out[i + n/2] * inv2 % MOD;
//         }
//         cur_exp = cur_exp * cur_root % MOD;
//     }
//     debug(n, out);
//     return out;
// }


void precalc(){
    factorial[0] = 1;
    for(int i = 1; i < 2 * MAXN; i++){
        factorial[i] = (int) (1LL * factorial[i-1] * i % MOD);
    }
    for(int i = 0; i < 2 * MAXN; i++){
        inv_factorial[i] = inverse(factorial[i]);
    }
}


void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi b(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];
    int q;
    cin >> q;
    vi queries(q);
    for(int i = 0; i < q; i++) cin >> queries[i];

    vi cnt(MAXN);
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    vi ans(q);
    for(int i = 0; i < k; i++){
        int height = b[i];
        int unique = 0, repeated = 0;
        for(int j = 1; j < height; j++){
            debug(j, cnt[j]);
            if(cnt[j] == 1) unique++;
            else if(cnt[j] > 1) repeated++;
        }
        debug(unique, repeated);
        vi p1(base);
        vi p2(base);
        for(int j = 0; j <= 2 * repeated; j++){
            p1[j] = ncr(2 * repeated, j);
        }
        for(int j = 0; j <= unique; j++){
            p2[j] = ncr(unique, j) * binexp(2, j) % MOD;
        }
        debug(p1, p2);
        debug("before fft");
        fft(p1, false);
        fft(p2, false);
        debug("after fft");
        vi res(base);
        for(int j = 0; j < base; j++){
            res[j] = (int) (1LL * p1[j] * p2[j] % MOD);
        }
        fft(res, true);
        debug(res);

        for(int j = 0; j < q; j++){
            if(queries[j] < 2 + 2 * height) continue;
            int needed = queries[j] / 2 - 1 - height;
            ans[j] = (ans[j] + res[needed]) % MOD;
        }
        debug("done iteration");
    }

    for(int i : ans) cout << i << endl;
}

int main(){
    precalc();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}