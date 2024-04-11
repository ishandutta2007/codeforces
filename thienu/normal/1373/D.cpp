#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// 4|3 |8 4
// 2|9 |4 5
ll max_alt(int n, vector<ll> &a, vector<ll> &b){
    vector<ll> prefa(n+1), prefb(n+1);
    // sum is prefa[n] - prefa[y] + prefb[y] - prefb[x] + prefa[x], y >= x
    // maximise - prefa[y] + prefb[y] - prefb[x] + prefa[x], y >= x
    // maximise (prefa[x] - prefb[x]) - (prefa[y] - prefb[y]), x <= y
    prefa[0] = 0;
    prefb[0] = 0;
    for(int i = 1; i <= n; i++){
        prefa[i] = prefa[i-1] + a[i-1];
        prefb[i] = prefb[i-1] + b[i-1];
    }
    ll maxi = 0;
    ll ans = 0;
    debug(prefa, prefb);
    for(int i = 0; i <= n; i++){
        maxi = max(maxi, prefa[i] - prefb[i]);
        ans = max(ans, (maxi - (prefa[i] - prefb[i])));
        debug(maxi, ans);
    }
    return prefa[n] + ans;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<ll> odds;
    vector<ll> evens;
    for(int i = 0; i < n; i++){
        if(i & 1){
            odds.push_back(v[i]);
        }
        else{
            evens.push_back(v[i]);
        }
    }
    if(n % 2 == 0){
        // 0 1 2 3
        ll a = max_alt(n/2, evens, odds);
        debug(evens, odds);
        vector<ll> t1 = vector<ll>(evens.begin()+1, evens.end());
        vector<ll> t2 = vector<ll>(odds.begin(), odds.end()-1);
        debug(t1, t2);
        ll b = max_alt(n/2-1, t1, t2);
        b += evens[0];
        debug(a, b);
        cout << max(a, b) << endl;
    }
    else{
        // (0 1) (2 3) 4
        vector<ll> t1 = vector<ll>(evens.begin(), evens.end()-1);
        ll a = max_alt(n/2, t1, odds);
        a += evens[n/2];
        vector<ll> t2 = vector<ll>(evens.begin()+1, evens.end());
        ll b = max_alt(n/2, t2, odds);
        b += evens[0];
        debug(a, b);
        cout << max(a, b) << endl;
        // 0 (1 2) (3 4)
    }
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