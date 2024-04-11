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

int INF = 1e9 + 5;

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    vi to_one(k);
    vi to_zero(k);
    for(int i = 0; i < k; i++){
        for(int j = i; j < n; j += k){
            if(s[j] == '1') to_zero[i]++;
        }
        int a = 0;
        for(int j = i; j < n; j += k) a++;
        vvi dp(a + 1, vi(3));
        for(int j = i; j < n; j += k){
            int pos = j / k;
            if(s[j] == '1'){
                dp[pos + 1][0] = dp[pos][0] + 1;
                dp[pos + 1][1] = min(dp[pos][0], dp[pos][1]);
                dp[pos + 1][2] = min({dp[pos][0], dp[pos][1], dp[pos][2]}) + 1;
            }
            else{
                dp[pos + 1][0] = dp[pos][0];
                dp[pos + 1][1] = min(dp[pos][0], dp[pos][1]) + 1;
                dp[pos + 1][2] = min({dp[pos][0], dp[pos][1], dp[pos][2]});
            }
        }
        to_one[i] = min({dp[a][2], dp[a][1], dp[a][0]});
    }

    debug(to_zero, to_one);
    
    int num = accumulate(to_zero.begin(), to_zero.end(), 0);
    int ans = num;
    for(int i = 0; i < k; i++){
        ans = min(ans, num - to_zero[i] + to_one[i]);
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