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


ll mul(ll a, ll b, ll MOD){
    return a * b % MOD;
}

ll add(ll a, ll b, ll MOD){
    return (a + b) % MOD;
}

ll binexp(ll a, ll b, ll MOD){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a, MOD);
        a = mul(a, a, MOD);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x, ll MOD){
    return binexp(x, MOD - 2, MOD);
}

int gcd(int a, int b){
    if(min(a, b) == 0) return max(a, b);
    return __gcd(a, b);
}


vll primes = {827664793, 1068156653, 1002289829, 1313020589, 1069632787};
const int N = 5;
const int A = 300005;

// vll primes = {1000000009};
// const int N = 1;
// const int A = 300005;

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int g = 0;
    for(int i : v){
        g = gcd(g, i);
    }
    if(g > 1){
        cout << -1 << endl;
        return;
    }
    debug(g);

    vvll factorial(N, vll(A)), inv_factorial(N, vll(A));
    for(int i = 0; i < N; i++){
        factorial[i][0] = 1;
        for(int j = 1; j < A; j++){
            factorial[i][j] = mul(factorial[i][j-1], j, primes[i]);
        }
        for(int j = 0; j < A; j++){
            inv_factorial[i][j] = inv(factorial[i][j], primes[i]);
        }
    }

    vi pr, lp(A);
    for(int i = 2; i < A; i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] < lp[i] && i * pr[j] < A; j++){
            lp[i * pr[j]] = pr[j];
        }
    }

    // cnt[i] is number of v[j], i | v[j]
    vi cnt(A);
    for(int i : v){
        cnt[i]++;
        // set<int> factors = {1};
        // while(i > 1){
        //     int l = lp[i];
        //     i /= l;
        //     set<int> new_factors = factors;
        //     for(int j : factors){
        //         new_factors.insert(j * l);
        //     }
        //     factors = new_factors;
        // }
        // // debug(factors);
        // for(int j : factors){
        //     cnt[j]++;
        // }
    }

    for(int i = 1; i < A; i++){
        for(int j = i+i; j < A; j+=i){
            cnt[i] += cnt[j];
        }
    }

    // debug(cnt);

    // return;
    int cand = 1;
    while(true){
        if(cand == 10){
            return;
        }
        debug(cand);
        bool ok = false;
        for(int pn = 0; pn < N; pn++){
            ll prime = primes[pn];
            vll dp(A);
            for(int i = A-1; i >= 0; i--){
                if(cnt[i] < cand){
                    dp[i] = 0;
                    continue;
                }
                dp[i] = mul(factorial[pn][cnt[i]], mul(inv_factorial[pn][cand], inv_factorial[pn][cnt[i] - cand], prime), prime);
                for(int j = i + i; j < A; j+=i){
                    dp[i] = (dp[i] + prime - dp[j]) % prime;
                }
            }
            debug(dp[1]);
            if(dp[1] > 0){
                ok = true;
                // break;
            }
        }
        if(ok){
            cout << cand << endl;
            return;
        }
        cand++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}