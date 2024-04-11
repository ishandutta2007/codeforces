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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi x(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vll pref(n);
    ll maxi = 0;
    // value, index
    vector<pair<ll, int>> maxima;
    for(int i = 0; i < n; i++){
        if(i){
            pref[i] = pref[i-1] + a[i];
        }
        else{
            pref[0] = a[0];
        }
        if(pref[i] > maxi){
            maxima.push_back({pref[i], i});
        }
        maxi = max(maxi, pref[i]);
    }
    ll sum = pref[n-1];
    debug(pref, maxima, sum, maxi);

    while(m--){
        ll x;
        cin >> x;
        if(sum <= 0 && x > maxi){
            cout << -1 << " ";
            continue;
        }
        debug("bruh");
        ll diff = (ll) x - maxi;
        ll cycle = max(0ll, (sum > 0 ? ((diff + sum - 1) / sum) : 0));
        ll inst = cycle * n;
        ll cur = sum * cycle;
        debug("pog");
        debug(diff, cycle, inst, cur);
        if(cur >= x){
            cout << inst - 1 << " ";
        }
        else{
            auto p = lower_bound(maxima.begin(), maxima.end(), make_pair((ll) x - cur, -1));
            cout << p->second + inst << " ";
        }
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