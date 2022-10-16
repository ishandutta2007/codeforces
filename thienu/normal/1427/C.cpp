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

using vpipii = vector<pair<int, pair<int, int>>>;

int INF = 1e9 + 5;

int dist(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(){
    int r, n;
    cin >> r >> n;
    vpipii v;
    v.push_back({0, {1, 1}});
    for(int i = 0; i < n; i++){
        int t, x, y;
        cin >> t >> x >> y;
        v.push_back({t, {x, y}});
    }
    // ans before celeb i
    vi dp(n+1, -INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(i, 2000); j++){
            if(j == 2000) dp[i] = max(dp[i], dp[i-j] + 1);
            else{
                if(dist(v[i-j].second, v[i].second) <= v[i].first - v[i-j].first){
                    dp[i] = max(dp[i], dp[i-j] + 1);
                }
            }
        }
    }
    debug(dp);
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}