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

int INF = 1e9 + 7;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vvi horizontal(n, vi(m-1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            cin >> horizontal[i][j];
        }
    }
    vvi vertical(n-1, vi(m));
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            cin >> vertical[i][j];
        }
    }
    if(k & 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << "-1 ";
            }
            cout << endl;
        }
        return;
    }

    int t = k/2;

    vector<vvi> dp(t+1, vvi(n, vi(m)));
    for(int p = 1; p <= t; p++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[p][i][j] = min({
                    i > 0 ? dp[p-1][i-1][j] + vertical[i-1][j] : INF,
                    i+1 < n ? dp[p-1][i+1][j] + vertical[i][j] : INF,
                    j > 0 ? dp[p-1][i][j-1] + horizontal[i][j-1] : INF,
                    j+1 < m ? dp[p-1][i][j+1] + horizontal[i][j] : INF
                });
            }
        }
    }

    debug(dp);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dp[t][i][j] * 2 << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}