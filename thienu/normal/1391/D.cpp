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

// 11110101
// 00010101
// 11011011

vector<vector<char>> transpose(vector<vector<char>> &v, int n, int m){
    vector<vector<char>> r(m, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            r[j][i] = v[i][j];
    return r;
}

int INF = 1e9 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];
    if(n >= 4 && m >= 4){
        cout << -1 << endl;
        return;
    }
    if(m > n){
        v = transpose(v, n, m);
        swap(n, m);
    }

    if(m == 1){
        cout << 0 << endl;
        return;
    }
    else if(m == 2){
        int a = 0, b = 0;
        bool x = true;
        for(int i = 0; i < n; i++){
            if((v[i][0] - '0' + v[i][1] - '0' + (x ? 1 : 0)) % 2 == 0){
                a++;
            }
            else{
                b++;
            }
            x = !x;
        }
        cout << min(a, b) << endl;
        return;
    }
    else if(m == 3){
        vector<vector<int>> dp(n, vector<int>(8, INF));
        for(int i = 0; i < 8; i++){
            dp[0][i] = __builtin_popcount(i ^ (4 * (v[0][0]-'0') + 2 * (v[0][1]-'0') + 1 * (v[0][2]-'0')));
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 8; j++){
                for(int k = 0; k < 8; k++){
                    // check squares i-1 to i - validity
                    if(((j >> 0 & 1) + (j >> 1 & 1) + (k >> 0 & 1) + (k >> 1 & 1)) % 2 == 1
                     && ((j >> 2 & 1) + (j >> 1 & 1) + (k >> 2 & 1) + (k >> 1 & 1)) % 2 == 1){
                        dp[i][k] = min(dp[i][k], dp[i-1][j] + __builtin_popcount(k ^ (4 * (v[i][0]-'0') + 2 * (v[i][1]-'0') + 1 * (v[i][2]-'0'))));
                    }
                }
            }
        }
        
        int ans = INF;
        for(int i = 0; i < 8; i++){
            ans = min(ans, dp[n-1][i]);
        }
        cout << ans << endl;
        return;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}