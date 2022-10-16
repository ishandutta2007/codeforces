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


const ll MOD = 998244353;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll normalize(ll x){
    return ((x % MOD) + MOD) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return binexp(x, MOD - 2);
}

const int A = 1e5 + 5;
// const int A = 10;

void solve(){
    int n;
    cin >> n;
    vector<vpii> mult(A);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        for(int j = 1; j * j <= x; j++){
            if(x % j == 0){
                mult[j].push_back({x, y});
                if(j * j < x){
                    mult[x/j].push_back({x, y});
                }
            }
        }
    }
    debug(mult);

    vll dp(A);
    for(int i = A-1; i >= 1; i--){
        for(int j = i+i; j < A; j += i){
            dp[i] = add(dp[i], normalize(-dp[j]));
        }
        ll total = 0, lin = 0, sq = 0;
        for(pii p : mult[i]){
            total += p.second;
            lin = add(lin, mul(p.first, p.second));
            sq = add(sq, mul(mul(p.first, p.first), p.second)); 
        }
        ll prod = add(mul(lin, lin), normalize(-sq));
        debug(i, total, lin, sq);
        ll km3 = total >= 3 ? binexp(2, total - 3) : 0;
        ll km2 = total >= 2 ? binexp(2, total - 2) : 0;
        ll same = 0, different = 0;
        if(total >= 2){
            same = mul(normalize(total-1), km2);
        }
        if(total >= 3){
            different = add(mul(normalize(total-2), km3), km2);
        }else if(total == 2){
            different = km2;
        }
        debug(i, same, different, sq, prod);
        debug(add(mul(sq, same), mul(prod, different)));
        dp[i] = add(dp[i], add(mul(sq, same), mul(prod, different)));
    }
    cout << dp[1] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}