//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const ll mod = (ll)1e9 + 7;

inline ll add(ll x, ll y){
    x += y;
    return x >= mod ? x - mod : x;
}
inline void iadd(ll & x, ll y){
    x += y;
    x -= x >= mod ? mod : 0;
}
inline ll sub(ll x, ll y){
    x -= y;
    return x < 0 ? x + mod : x;
}
inline void isub(ll & x, ll y){
    x -= y;
    x += x < 0 ? mod : 0;
}
inline ll mul(ll x, ll y){
    return (x * y) % mod;
}
inline void imul(ll & x, ll y){
    x *= y;
    x %= mod;
}

inline ll modpow(ll a, ll n){
    ll result = 1;
    while(n){
        if(n&1)
            imul(result, a);
        imul(a, a);
        n >>= 1;
    }
    return result;
}
struct PowerSum{
    int k;
    vector<ll> y;
    vector<ll> inv, ifac;
    vector<ll> forw, backw;
    PowerSum(int _k):k(_k){
        y = vector<ll>(k + 2, 0);
        for(int i = 1; i <= k + 1; i++){
            y[i] = y[i - 1];
            iadd(y[i], modpow(i, k));
        } 
        inv = vector<ll>(k + 2, 1);
        ifac = vector<ll>(k + 2, 1);
        for(int i = 2; i <= k + 1; i++){
            inv[i] = sub(0, mul(mod/i, inv[mod % i]));
            ifac[i] = mul(ifac[i - 1], inv[i]);
        }
        forw = vector<ll>(k + 2, 0);
        backw = vector<ll>(k + 2, 0);
    }
    ll eval(ll x){
        x %= mod;
        forw[0] = 1;
        for(int i = 1; i <= k + 1; i++){
            forw[i] = mul(forw[i - 1], sub(x, i - 1));
        }
        backw[k + 1] = 1;
        for(int i = k; i >= 0; i--){
            backw[i] = mul(backw[i + 1], sub(x, i + 1));
        }
        ll ans = 0;
        for(int i = 0; i <= k + 1; i++){
            ll curr = mul(y[i], mul(mul(forw[i], backw[i]), mul(ifac[i], ifac[k + 1 - i])));
            if((k + 1 - i)&1)
                curr = curr ? mod - curr : 0;
            iadd(ans, curr);
        }
        return ans;
    }
};


int main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    auto solver = PowerSum(k);
    cout << solver.eval(n) << endl;
    return 0;
}