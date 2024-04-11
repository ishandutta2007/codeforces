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
    int n;
    cin >> n;
    vector<int> v(2*n);
    for(int i = 0; i < 2*n; i++){
        cin >> v[i];
        v[i]--;
    }

    vector<int> pieces;

    vector<int> used(2*n);
    int next = 2*n-1;
    int cnt = 0;
    for(int i = 2*n-1; i >= 0; i--){
        cnt++;
        while(used[next]){
            next--;
        }
        if(v[i] == next){
            pieces.push_back(cnt);
            cnt = 0;
        }
        used[v[i]] = 1;
    }

    debug(pieces);

    int p = pieces.size();

    // knapsack to n
    // dp[before idx][weight]
    vector<vector<int>> dp(p+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= p; i++){
        for(int j = 0; j <= n; j++){
            if(dp[i-1][j]) dp[i][j] = 1;
            if(j-pieces[i-1] >= 0 && dp[i-1][j-pieces[i-1]]) dp[i][j] = 1;
        }
    }
    debug(dp);
    cout << (dp[p][n] ? "YES" : "NO") << endl;
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