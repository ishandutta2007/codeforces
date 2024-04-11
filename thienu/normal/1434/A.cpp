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

int F = 6;
int INF = 1e9 + 7;

void solve(){
    vector<int> a(F);
    for(int i = 0; i < F; i++) cin >> a[i];
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];


    sort(a.begin(), a.end(), greater<int>());
    sort(v.begin(), v.end());

    debug(a, v);

    vector<int> cur(n, 0);

    int ans = INF;
    int left = v[0] - a[0];
    int right = v[n-1] - a[0];
    
    multiset<pair<int, int>> poi;
    for(int i = 0; i < n; i++) poi.insert(make_pair(v[i] - a[0], i));

    debug(poi);

    ans = min(ans, right - left);
    while(!poi.empty()){
        debug(left, right, poi, cur);
        auto p = *poi.begin();

        if(cur[p.second] == F - 1) break;

        cur[p.second]++;

        poi.erase(poi.begin());
        
        poi.insert({v[p.second] - a[cur[p.second]], p.second});
        right = max(right, v[p.second] - a[cur[p.second]]);
        left = poi.begin()->first;
        ans = min(ans, right - left);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}