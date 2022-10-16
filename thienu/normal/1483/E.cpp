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

vvll dp;
ll INF = 1e17;

// true if >=
bool interact(ll x, ll &balance){
    cout << "? " << x << endl;
    string s;
    cin >> s;
    if(s == "Fired!"){
        exit(-1);
    }
    balance += x * (s == "Lucky!" ? 1 : -1);
    return s == "Lucky!"; 
}

void solve(){
    ll balance = 1;
    ll lower = (1ll << 46), upper = 100000000000000ll;
    int queries = 105;
    for(int i = 0; i <= 46; i++){
        bool res = interact(1ll << i, balance);
        queries--;
        if(!res){
            if(i == 0){
                cout << "! 0" << endl;
                return;
            }
            lower = (1ll << (i-1));
            upper = (1ll << i) - 1;
            break;
        }
    }
    debug(lower, upper, balance);

    while(lower < upper && queries > 0){
        debug(lower, upper);
        ll i = max(2ll, balance / lower);
        ll width = upper - lower + 1;
        
        ll a = dp[i-2][queries-1];
        ll b = dp[i+1][queries-1];
        ll s = max(2ll, (ll) ((double) width * a / (a+b)));
        debug(width, i, queries, a, b, s);

        ll t;
        
        if(a + b > width){
            t = lower + s - 1;
        }
        else{
            t = upper - b + 1;
        }
        if(t > balance){
            interact(lower, balance);
        }
        else{
            bool res = interact(t, balance);
            if(res){
                lower = t;
            }
            else{
                upper = t - 1;
            }
        }
        queries--;
    }
    debug(lower, upper);
    cout << "! " << lower << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp.resize(200);
    fill(dp.begin(), dp.end(), vll(200));
    for(int i = 0; i < 200; i++){
        dp[i][0] = 1;
    }
    for(int j = 1; j <= 190; j++){
        for(int i = 0; i <= 190; i++){
            if(j >= 5 && i < 2 || j < 5 && i < 1){
                dp[i][j] = min(dp[i+1][j-1], INF);
            }
            else{
                if(j < 5){
                    dp[i][j] = min(dp[i+1][j-1] + dp[i-1][j-1], INF);
                }
                else{
                    dp[i][j] = min(dp[i+1][j-1] + dp[i-2][j-1], INF);
                }
            }
        }
    }

    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}