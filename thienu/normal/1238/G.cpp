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

struct Water{
    int t, a, b;
    Water(int t, int a, int b) : t(t), a(a), b(b) {}
};

bool operator<(Water x, Water y){
    return x.t < y.t;
}

void solve(){
    int n, m, c, c0;
    cin >> n >> m >> c >> c0;
    vector<Water> v;
    for(int i = 0; i < n; i++){
        int t, a, b;
        cin >> t >> a >> b;
        v.push_back(Water(t, a, b));
    }
    v.push_back(Water(m, 0, 0));
    sort(v.begin(), v.end());
    multiset<pii> price;
    price.insert({0, c0});
    int total = c0;
    int last = 0;
    ll ans = 0;
    for(Water x : v){
        int delta = x.t - last;
        while(delta > 0){
            if(price.empty()){
                cout << -1 << endl;
                return;
            }
            pii p = *price.begin();
            if(p.second <= delta){
                price.erase(price.begin());
                delta -= p.second;
                total -= p.second;
                ans += 1LL * p.first * p.second;
            }else{
                price.erase(price.begin());
                price.insert({p.first, p.second-delta});
                ans += 1LL * p.first * delta;
                total -= delta;
                delta = 0;
            }
        }
        price.insert({x.b, x.a});
        debug(x.t, price, ans);
        total += x.a;
        while(total > c){
            pii p = *prev(price.end());
            if(total - p.second >= c){
                price.erase(prev(price.end()));
                total -= p.second;
            }else{
                price.erase(prev(price.end()));
                price.insert({p.first, p.second - total + c});
                total = c;
            }
        }
        last = x.t;
    }
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