#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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

void solve(){
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    // dp[i][j] is max score after i moves, j to left -> pos = i-j
    vector<vector<int>> dp(k+1, vector<int>(z+1));
    dp[0][0] = v[0];
    for(int j = 0; j <= z; j++){
        for(int i = 0; i <= k; i++){
            if(j == 0){
                if(i == 0) continue;
                dp[i][j] = dp[i-1][j] + v[i];
                continue;
            }
            int pos = i-2*j;
            debug(i, j, pos);
            if(pos < 0) continue;
            if(pos == 0){
                dp[i][j] = dp[i-1][j-1] + v[0];
            }
            else{
                dp[i][j] = max((pos == n-1 ? 0 : (dp[i-1][j] + v[pos])), dp[i-1][j-1] + v[pos]);
            }
        }
    }
    debug(dp);
    int maxi = 0;
    for(int i = 0; i <= z; i++){
        maxi = max(maxi, dp[k][i]);
    }
    cout << maxi << endl;
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