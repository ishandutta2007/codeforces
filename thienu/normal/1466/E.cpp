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

ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vi bit_sums(60);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 60; j++){
            bit_sums[j] = (bit_sums[j] + ((ll) ((v[i] >> j) & 1) << j)) % MOD;
        }
    }

    debug(bit_sums);

    int ans = 0;

    for(int i = 0; i < n; i++){
        int sum_or = 0;
        int sum_and = 0;
        for(int j = 0; j < 60; j++){
            if((v[i] >> j) & 1){
                sum_or = (sum_or + ((ll) ((1LL << j) % MOD) * n) % MOD) % MOD;
                sum_and = (sum_and + bit_sums[j]) % MOD;
            }
            else{
                sum_or = (sum_or + bit_sums[j]) % MOD;
            }
        }
        ans = (ans + ((ll) sum_or * sum_and)) % MOD;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}