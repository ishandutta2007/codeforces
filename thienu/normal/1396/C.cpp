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
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    ll n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<ll> back(n+1);
    vector<ll> not_back(n+1);
    back[0] = -d;
    not_back[0] = -d;
    // guaranteed back <= not_back
    for(int i = 0; i < n; i++){
        not_back[i+1] = min({back[i] + 3 * d + min({(v[i] + 2) * r1, v[i] * r1 + r3, r2 + r1}),
                             not_back[i] + d + r1 * v[i] + r3});
        back[i+1] = min({not_back[i+1],
                         not_back[i] + d + min({(v[i] + 2) * r1, v[i] * r1 + r3, r2 + r1})});
    }
    debug(not_back, back);
    vector<ll> ending(n+1);
    ending[n] = r1 * v[n-1] + r3;
    for(int i = n-1; i >= 1; i--){
        ending[i] = ending[i+1] + 2 * d + min({(v[i-1] + 2) * r1, v[i-1] * r1 + r3, r2 + r1});
    }
    debug(ending);

    ll ans = not_back[n];
    for(int i = 0; i < n; i++){
        ans = min(ans, not_back[i] + ending[i+1] + d);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}