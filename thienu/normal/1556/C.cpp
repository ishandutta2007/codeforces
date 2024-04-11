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
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    if(n & 1){
        n--;
        v.pop_back();
    }
    if(n == 0){
        cout << 0 << endl;
        return;
    }

    vll delta(n+1);
    for(int i = 0; i < n; i++){
        delta[i+1] = delta[i] + ((i & 1) ? -1LL : 1LL) * v[i];
    }
    debug(delta);
    ll ans = 0;
    // [l, r)
    for(int l = 0; l < n; l++){
        ll min_delta = delta[l];
        for(int r = l; r < n; r++){
            min_delta = min(min_delta, delta[r+1]);
            ll l0, l1, r0, r1;
            if(l > 0){
                l0 = delta[l], l1 = delta[l-1] + ((l & 1) ? 1LL : -1LL);
            }else{
                l0 = l1 = delta[0];
            }
            if(r < n-1){
                r0 = delta[r+1], r1 = delta[r+2] + ((r & 1) ? -1LL : 1LL);
            }else{
                r0 = r1 = delta[n];
            }
            debug(l, r, l0, l1, r0, r1);
            if(l0 > l1) swap(l0, l1);
            if(r0 > r1) swap(r0, r1);
            ll mini = max(l0, r0);
            ll maxi = min({min_delta, l1, r1});
            debug(mini, maxi);
            if(maxi < mini) continue;
            ans += maxi - mini + 1;
        }
    }
    debug(ans);
    for(int i = 0; i < n; i+=2){
        ans += min(v[i], v[i+1]) - 1;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}