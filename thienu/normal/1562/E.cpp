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

bool smaller(int a, int b, string &s, vvi &lcp){
    if(a+lcp[a][b] == s.size()){
        return true;
    }else if(b+lcp[a][b] == s.size()){
        return false;
    }
    return s[a+lcp[a][b]] < s[b+lcp[a][b]];
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vvi lcp(n+1, vi(n+1));
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(i == j) lcp[i][j] = n-i;
            else if(s[i] == s[j]){
                lcp[i][j] = lcp[i+1][j+1] + 1;
            }else{
                lcp[i][j] = 0;
            }
        }
    }
    vi dp(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        dp[i] = n-i;
        for(int j = 0; j < i; j++){
            if(smaller(j, i, s, lcp)){
                debug(j, i);
                dp[i] = max(dp[i], dp[j] + (n-i-lcp[i][j]));
            }
        }
        ans = max(dp[i], ans);
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