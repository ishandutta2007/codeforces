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

ll sub(ll a, ll b){
    return (a - b + MOD) % MOD;
}

ll normalize(ll x){
    return ((x % MOD) + MOD) % MOD;
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

const int N = 5e5 + 20;
int fact[N];
int inv_fact[N];
void precomp(){ // don't forget to call precomp()!
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = mul(fact[i-1], i);
    }
    for(int i = 0; i < N; i++){
        inv_fact[i] = inv(fact[i]);
    }
}

ll ncr(ll n, ll r){
    assert(n >= 0);
    if(r < 0 || r > n) return 0;
    return mul(fact[n], mul(inv_fact[r], inv_fact[n-r]));
}

void solve(){
    int n, k;
    cin >> n >> k;

    vvll same(n+1, vll(2));
    same[0][0] = 1;
    for(int i = 1; i <= n; i++){
        same[i][0] = same[i-1][1];
        same[i][1] = add(mul(k-1, same[i-1][0]), mul(k-2, same[i-1][1]));
    }
    debug(same);
    vvll diff(n+1, vll(2));
    diff[0][1] = 1;
    for(int i = 1; i <= n; i++){
        diff[i][0] = diff[i-1][1];
        diff[i][1] = add(mul(k-1, diff[i-1][0]), mul(k-2, diff[i-1][1]));
    }
    debug(diff);


    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = 1;
    {
        bool first = true;
        int run = 0;
        int lst = -1;
        for(int i = 0; i < n; i+=2){
            if(v[i] != -1){
                if(first){
                    ans = mul(ans, binexp(k-1, run));
                    first = false;
                    lst = v[i];
                }else{
                    if(v[i] == lst){
                        ans = mul(ans, same[run][1]);
                    }else{
                        ans = mul(ans, diff[run][1]);
                    }
                    lst = v[i];
                }
                run = 0;
            }else{
                run++;
            }
        }
        debug(first, run);
        if(!first) ans = mul(ans, binexp(k-1, run));
        else ans = mul(ans, mul(k, binexp(k-1, run-1)));
    }
    {
        bool first = true;
        int run = 0;
        int lst = -1;
        for(int i = 1; i < n; i+=2){
            if(v[i] != -1){
                if(first){
                    ans = mul(ans, binexp(k-1, run));
                    first = false;
                    lst = v[i];
                }else{
                    if(v[i] == lst){
                        ans = mul(ans, same[run][1]);
                    }else{
                        ans = mul(ans, diff[run][1]);
                    }
                    lst = v[i];
                }
                run = 0;
            }else{
                run++;
            }
        }
        debug(first, run);
        if(!first) ans = mul(ans, binexp(k-1, run));
        else ans = mul(ans, mul(k, binexp(k-1, run-1)));
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    solve();
    return 0;
}