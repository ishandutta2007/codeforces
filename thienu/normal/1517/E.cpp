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

ll MOD = 998244353;
ll INF = 1e18;

ll pattern(int n, vi &v, ll c_threshold){
    debug(c_threshold);
    if(c_threshold < 0) return 0;
    vll pref(n+1);
    vll pref_alt_even(n+1);
    vll pref_alt_odd(n+1);
    for(int i = 0; i < n; i++){
        pref[i+1] = pref[i] + v[i];
        pref_alt_even[i+1] = pref_alt_even[i] + ((i & 1) ^ 1) * v[i];
        pref_alt_odd[i+1] = pref_alt_odd[i] + (i & 1) * v[i];
    }
    debug(pref, pref_alt_odd, pref_alt_even);
    if(n & 1){
        pref_alt_odd.push_back(INF);
        pref_alt_even.push_back(*prev(pref_alt_even.end()));
    }
    else{
        pref_alt_even.push_back(INF);
        pref_alt_odd.push_back(*prev(pref_alt_odd.end()));
    }

    ll ans = 0;
    // which element to split1 before
    for(int i = 0; i <= n; i++){
        if(pref[i] > c_threshold) break;
        int split2;
        if(i & 1){
            // c on even
            int left = -1;
            int right = n+1;
            while(left < right){
                int mid = left + (right - left + 1) / 2;
                debug(left, right, mid);
                if(pref_alt_even[mid] - pref_alt_even[i] > c_threshold - pref[i]){
                    right = mid - 1;
                }
                else{
                    left = mid;
                }
            }
            split2 = left-1;
        }
        else{
            // c on odd
            int left = -1;
            int right = n+1;
            while(left < right){
                int mid = left + (right - left + 1) / 2;
                debug(left, right, mid);
                if(pref_alt_odd[mid] - pref_alt_odd[i] > c_threshold - pref[i]){
                    right = mid - 1;
                }
                else{
                    left = mid;
                }
            }
            split2 = left-1;
        }
        debug(i, split2);
        if(split2 >= i){
            ans = ans + ((split2 - i) / 2 + 1) % MOD;
        }
    }
    debug(ans);
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vi v(n);
    ll total = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        total += v[i];
    }
    ll total_c = (total - 1) / 2;

    if(n <= 3){
        // brute force
        int ans = 0;
        for(int mask = 0; mask < (1 << n); mask++){
            ll sum = 0;
            for(int i = 0; i < n; i++){
                if((mask >> i) & 1){
                    sum += v[i];
                }
            }
            if(sum <= total_c) ans++;
        }
        cout << ans << endl;
        return;
    }

    ll ans = 0;


    //c--p
    {
    vi x = vi(v.begin() + 1, v.end() - 1);
    ans = (ans + pattern(n-2, x, total_c - v[0])) % MOD;
    }
    
    //pc--p
    {
    vi x = vi(v.begin() + 2, v.end() - 1);
    ans = (ans + pattern(n-3, x, total_c - v[1])) % MOD;
    }
    
    //c--pc
    {
    vi x = vi(v.begin() + 1, v.end() - 2);
    ans = (ans + pattern(n-3, x, total_c - v[0] - v[n-1])) % MOD;
    }
    
    //pc--pc
    {
    vi x = vi(v.begin() + 2, v.end() - 1);
    ans = (ans + pattern(n-4, x, total_c - v[1] - v[n-1])) % MOD;
    }

    //p...pc...c
    {
        ans = (ans + 1) % MOD;
        vll suf(n+1);
        for(int i = n-1; i >= 0; i--){
            suf[i] = suf[i+1] + v[i];
            if(suf[i] <= total_c){
                ans = (ans + 1) % MOD;
            }
            else{
                break;
            }
        }
    }

    debug(ans);
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