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

using ull = unsigned ll;

ll MOD;

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

vvll multiply(vvll a, vvll b){
    debug(a, b);
    int x = a.size();
    int y = b.size();
    int z = b[0].size();
    assert(y == a[0].size());
    vvll ans(x, vll(z));
    for(int i = 0; i < x; i++){
        for(int j = 0; j < z; j++){
            for(int k = 0; k < y; k++){
                ans[i][j] = (ans[i][j] + ((a[i][k] * b[k][j]) % MOD)) % MOD;
                // debug(a[i][k] * b[k][j], ans[i][j]);
            }
        }
    }
    debug(ans);
    return ans;
}

vvll mat_binexp(vvll a, ll b){
    // vvll ans = {{1, 0}, {0, 1}};
    vvll ans(2, vll(2));
    ans[0][0] = 1;
    ans[1][1] = 1;
    debug(a);
    while(b){
        if(b & 1){
            ans = multiply(ans, a);
        }
        a = multiply(a, a);
        b >>= 1;
        debug(a, b);
    }
    return ans;
}

void solve(){
    ll n, k;
    int l;
    cin >> n >> k >> l >> MOD;
    
    if(MOD == 1){
        cout << 0 << endl;
        return;
    }

    // vvll trans = {{0, 1}, {1, 1}};
    vvll trans(2, vll(2, 1));
    trans[0][0] = 0;
    vvll initial(2, vll(1));
    initial[0][0] = 1;
    initial[1][0] = 2;
    debug(trans, initial);
    vvll trans_pow = mat_binexp(trans, n);
    debug(trans_pow);
    vvll final = multiply(trans_pow, initial);
    debug(final);
    ll zero = final[0][0];
    debug(binexp(2, n));
    ll one = ((binexp(2, n) - zero) % MOD + MOD) % MOD;
    debug(zero, one);

    ll ans = 1;
    for(int i = 0; i < 64; i++){
        if(l <= i && (k >> i) & 1){
            cout << 0 << endl;
            return;
        }
        else if(l > i){
            if((k >> i) & 1){
                ans = ans * one % MOD;
            }
            else{
                ans = ans * zero % MOD;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}