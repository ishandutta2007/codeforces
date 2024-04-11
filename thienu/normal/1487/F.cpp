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

using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;

const int N = 255;
const int M = 30;
// const int N = 10;
// const int M = 3;
// i, carry, pos, neg
int dp[2][2*M+1][N][N];
// vvvvi dp(2, vvvi(2*M+1, vvi(N, vi(N))));


const int INF = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    s = '0' + s;
    int n = s.size();
    debug(n);
    for(int j = 0; j <= 2*M; j++){
        for(int k = 0; k < N; k++){
            for(int l = 0; l < N; l++){
                // debug(j, k, l);
                dp[0][j][k][l] = INF;
            }
        }
    }
    debug("inf");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[0][M][i][j] = 0;
        }
    }
    debug("setup");
    int lasti = 0;
    for(int i = 0; i < n; i++){
        int oldi = i & 1;
        int newi = oldi ^ 1;
        lasti = newi;
        for(int j = 0; j <= 2*M; j++){
            for(int k = 0; k < N; k++){
                for(int l = 0; l < N; l++){
                    dp[newi][j][k][l] = INF;
                }
            }
        }
        for(int carry = -M; carry <= M; carry++){
            for(int pos = N-1; pos >= 0; pos--){
                for(int neg = N-1; neg >= 0; neg--){
                    if(pos > 0) dp[oldi][carry+M][pos-1][neg] = min(dp[oldi][carry+M][pos-1][neg], dp[oldi][carry+M][pos][neg]); 
                    if(neg > 0) dp[oldi][carry+M][pos][neg-1] = min(dp[oldi][carry+M][pos][neg-1], dp[oldi][carry+M][pos][neg]);
                    int digit = carry + pos - neg;
                    int c = digit / 10;
                    digit %= 10;
                    if(digit < 0){
                        digit += 10;
                        c--;
                    }
                    if(digit == s[n-i-1]-'0'){
                        debug(i, M, pos, neg, c);
                        dp[newi][c+M][pos][neg] = min(dp[newi][c+M][pos][neg], dp[oldi][carry+M][pos][neg] + pos + neg);
                    }
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans = min(ans, dp[lasti][M][i][j]);
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}