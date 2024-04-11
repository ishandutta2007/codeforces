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

void solve(){
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    int l = 0, r = n-1;
    ll buf = 0;
    ll bought = 0;
    vll suf(n+1);
    for(int i = n-1; i >= 0; i--){
        suf[i] = suf[i+1] + v[i].second;
    }
    debug(v, suf);
    for(int i = 0; i < n; i++){
        ll rem = max(0LL, suf[i] - buf);
        debug(i, rem);
        if(rem < v[i].second){
            ll ones = max(0LL, min(rem, v[i].first - bought));
            ll twos = rem - ones;
            bought += rem;
            debug(i, ones, twos);
            ans += twos * 1 + (v[i].second - twos) * 2;
        }
        else{
            ll boost = max(0LL, v[i].first - bought);
            ll extra_rem = rem - v[i].second;
            debug(boost, extra_rem);
            ll acquired_boost = min(boost, extra_rem);
            bought += acquired_boost + v[i].second;
            buf += acquired_boost;
            if(acquired_boost == boost){
                ans += v[i].second * 1;
            }
            else{
                ll ones = min(boost - acquired_boost, v[i].second);
                ans += ones * 2 + (v[i].second - ones) * 1;
            }
        }
        debug(i, bought, ans, buf);
    }
    debug(bought);
    assert(bought == suf[0]);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}