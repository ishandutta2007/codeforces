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
    int n, k, q;
    cin >> n >> k >> q;
    vll v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vvll freq(k+1, vll(n, 1));
    for(int i = 1; i <= k; i++){
        freq[i][0] = freq[i-1][1];
        freq[i][n-1] = freq[i-1][n-2];
        for(int j = 1; j+1 < n; j++){
            freq[i][j] = (freq[i-1][j-1] + freq[i-1][j+1]) % MOD;
        }
    }
    debug(freq);

    vll mult(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            mult[i] = (mult[i] + freq[j][i] * freq[k-j][i] % MOD) % MOD;
        }
    }
    debug(mult);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + mult[i] * v[i] % MOD) % MOD;
    }

    while(q--){
        int pos;
        ll val;
        cin >> pos >> val;
        pos--;
        ll delta = ((val - v[pos]) % MOD + MOD) % MOD;
        ans = (ans + mult[pos] * delta % MOD) % MOD;
        cout << ans << endl;
        v[pos] = val;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}