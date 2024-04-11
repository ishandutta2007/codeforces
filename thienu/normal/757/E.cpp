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

const int MAXR = 1e6 + 5;
const int MAXA = 19;
const ll MOD = 1e9 + 7;
vvll dp(MAXR+1, vll(MAXA+1));
vi lp(MAXR+1);
vi pr;

void precalc(){
    for(int i = 0; i <= MAXR; i++){
        for(int j = 0; j <= MAXA; j++){
            if(i == 0){
                if(j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 2;
                }
            }
            else{
                // ll sum = 0;
                // for(int k = 0; k <= j; k++){
                //     sum = (sum + dp[i-1][k]) % MOD;
                // }
                // dp[i][j] = sum;
                if(j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
                }
            }
        }
    }

    for(int i = 2; i <= MAXR; i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAXR; j++){
            lp[i * pr[j]] = pr[j];
        }
    }
}

void solve(){
    int r, n;
    scanf("%d %d", &r, &n);
    // factorise
    map<int, int> factors;
    while(n > 1){
        factors[lp[n]]++;
        n /= lp[n];
    }

    debug(factors);

    ll ans = 1;
    for(auto it = factors.begin(); it != factors.end(); it++){
        ans = ans * dp[r][it->second] % MOD;
    }
    printf("%d\n", ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();
    int tc;
    scanf("%d", &tc);
    while(tc--){
        solve();
    }
    return 0;
}