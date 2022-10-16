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

int gcd(int a, int b){
    if(min(a, b) > 0) return __gcd(a, b);
    return max(a, b);
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vi dp(n+1);
    map<pii, int> last;
    vi a(n+1), b(n+1);
    for(int i = 0; i < n; i++){
        a[i+1] = a[i];
        b[i+1] = b[i];
        if(s[i] == 'K') a[i+1]++;
        else b[i+1]++;
    }
    for(int i = 1; i <= n; i++){
        int p = a[i], q = b[i];
        int g = gcd(p, q);
        int f = p/g + q/g;
        int l = last[make_pair(p / g, q / g)];
        debug(p, q, make_pair(p / g, q / g), l);
        int z = dp[l];
        for(int j = l+f; j <= i; j+=f){
            if((ll) a[j] * q == (ll) b[j] * p){
                z++;
            }
        }
        dp[i] = z;
        last[make_pair(p / g, q / g)] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << dp[i] << ' ';
    }
    cout << endl;
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