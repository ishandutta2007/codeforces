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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 5;

void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    int threshold = (n+1)/2;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        ll x = 0;
        for(int j = 0; j < m; j++){
            if(s[j] == '1'){
                x |= (1LL << j);
            }
        }
        a[i] = x;
    }
    
    vi order(n);
    for(int i = 0; i < n; i++) order[i] = i;
    shuffle(order.begin(), order.end(), rng);
    debug(order);

    int best = 0;
    ll ans = 0;

    for(int o = 0; o < min(n, 50); o++){
        ll x = a[order[o]];
        debug(x);
        vi idx;
        int sz = 0;
        for(int i = 0; i < m; i++){
            if((x >> i) & 1){
                sz++;
                idx.push_back(i);
            }
        }
        vi cnt(1 << sz);
        for(int i = 0; i < n; i++){
            int mask = 0;
            for(int b = 0; b < sz; b++){
                if((a[i] >> idx[b]) & 1){
                    mask |= (1 << b);
                }
            }
            cnt[mask]++;
        }
        for(int b = 0; b < sz; b++){
            for(int i = 0; i < (1 << sz); i++){
                if((i >> b) & 1){
                    cnt[i ^ (1 << b)] += cnt[i];
                }
            }
        }
        debug(cnt);
        for(int i = 0; i < (1 << sz); i++){
            if(cnt[i] >= threshold && __builtin_popcount(i) > best){
                best = __builtin_popcount(i);
                ans = 0;
                for(int b = 0; b < sz; b++){
                    if((i >> b) & 1){
                        ans |= (1LL << idx[b]);
                    }
                }
            }
        }
    }
    // cout << ans << endl;
    for(int b = 0; b < m; b++){
        if((ans >> b) & 1LL){
            cout << '1';
        }
        else{
            cout << '0';
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}