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

const ll MOD = 998244353;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return binexp(x, MOD - 2);
}

void solve(){
    int n;
    cin >> n;
    vi inst(n);
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == '-'){
            inst[i] = -1;
        }
        else{
            int x;
            cin >> x;
            inst[i] = x;
        }
    }
    debug(inst);
    ll ans = 0;
    for(int d = 0; d < n; d++){
        if(inst[d] == -1) continue;
        vll ways(n);
        ways[0] = 1;
        for(int i = 0; i < n; i++){
            if(i < d){
                vll new_ways(n);
                if(inst[i] == -1){
                    new_ways[0] = add(ways[1], mul(ways[0], 2));
                    for(int j = 1; j < n-1; j++){
                        new_ways[j] = add(ways[j+1], ways[j]);
                    }
                    new_ways[n-1] = ways[n-1];
                }else if(inst[i] <= inst[d]){
                    new_ways[0] = ways[0];
                    for(int j = 1; j < n; j++){
                        new_ways[j] = add(ways[j-1], ways[j]);
                    }
                }else{
                    for(int j = 0; j < n; j++){
                        new_ways[j] = mul(ways[j], 2);
                    }
                }
                ways = new_ways;
            }
            else if(i > d){
                vll new_ways(n);
                if(inst[i] == -1){
                    for(int j = 0; j < n-1; j++){
                        new_ways[j] = add(ways[j+1], ways[j]);
                    }
                    new_ways[n-1] = ways[n-1];
                }else if(inst[i] < inst[d]){
                    new_ways[0] = ways[0];
                    for(int j = 1; j < n; j++){
                        new_ways[j] = add(ways[j-1], ways[j]);
                    }
                }else{
                    for(int j = 0; j < n; j++){
                        new_ways[j] = mul(ways[j], 2);
                    }
                }
                ways = new_ways;
            }
        }
        debug(d, ways);
        ll s = 0;
        for(int i = 0; i < n; i++){
            s = add(s, ways[i]);
        }
        ans = add(ans, mul(s, inst[d]));
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}