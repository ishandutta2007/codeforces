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

ll INF = (ll) 2e18 + 7;

pair<ll, ll> calc(int n, int k, int add){
    if(add == 0){
        return {1, n};
    }
    int period = k / __gcd(k, add);
    int add_per_period = (ll) period * add / k; // in blocks, mod period
    debug(add, period, add_per_period);
    ll mini = INF, maxi = 0;
    for(ll i = add_per_period; i < (ll) period * n + add_per_period; i += period){
        ll ans = (ll) period * ((ll) n / __gcd((ll) i, (ll) n));
        // debug(i, ans);
        mini = min(ans, mini);
        maxi = max(ans, maxi);
    }
    return {mini, maxi};
}

void solve(){
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    ll mini = INF, maxi = 0;
    for(int i = -1; i <= 1; i+=2){
        for(int j = -1; j <= 1; j+=2){
            int add = ((b * j - a * i) % k + k) % k;
            pair<ll, ll> p = calc(n, k, add);
            debug(add, p);
            mini = min(mini, p.first);
            maxi = max(maxi, p.second);
        }
    }
    cout << mini << " " << maxi << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}