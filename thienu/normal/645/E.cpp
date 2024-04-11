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

int MOD = 1e9 + 7;

int min_index(vector<int> &v){
    int minv = 1e9 + 5;
    int mini;
    for(int i = 0; i < v.size(); i++){
        if(v[i] < minv){
            mini = i;
            minv = v[i];
        }
    }
    return mini;
}

void solve(){
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int m = t.size();

    vector<int> dp(n+m+1);
    vector<int> last_occ(k, -1);

    dp[0] = 1;
    for(int i = 0; i < m; i++){
        dp[i+1] = ((dp[i] * 2 - (last_occ[t[i] - 'a'] == -1 ? 0 : dp[last_occ[t[i] - 'a']])) % MOD + MOD) % MOD;
        last_occ[t[i] - 'a'] = i;
    }

    for(int i = m; i < m+n; i++){
        int mini = min_index(last_occ);
        debug(mini);
        dp[i+1] = ((dp[i] * 2 - (last_occ[mini] == -1 ? 0 : dp[last_occ[mini]])) % MOD + MOD) % MOD;
        last_occ[mini] = i;
    }

    debug(dp);

    cout << *(dp.end() - 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}