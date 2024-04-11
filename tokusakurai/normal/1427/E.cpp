#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

vector<tuple<ll, ll, int>> ans;

void solve(ll x){
    if(x == 1) return;
    int n = 64-__builtin_clzll(x);

    if(__builtin_popcountll(x) < n){
        rep(i, n-1) ans.eb(x<<i, x<<i, 0);

        ans.eb(x, x<<(n-1), 0), ans.eb(x, x<<(n-1), 1);
        ll a = x+(x<<(n-1)), b = x^(x<<(n-1));

        ans.eb(a, b, 1);
        a ^= b;

        while(true){
            int k = 64-__builtin_clzll(a);
            if(k < n) break;
            ans.eb(a, x<<(k-n), 1);
            a ^= x<<(k-n);
        }

        if(a&1) return solve(a);
        else{
            int m = 64-__builtin_clzll(a);
            rep(i, n-m) ans.eb(a<<i, a<<i, 0);

            ans.eb(x, a<<(n-m), 1);
            x ^= a<<(n-m);
            return solve(x);
        }
    }
    else{
        ans.eb(x, x, 0);

        ans.eb(x, x<<1, 0), ans.eb(x, x<<1, 1);
        ll a = x+(x<<1), b = x^(x<<1);

        ans.eb(b, x, 0);
        b += x;

        ans.eb(a, b, 1);
        a ^= b;
        return solve(a);
    }
}

int main(){
    ll x; cin >> x;

    solve(x);

    cout << sz(ans) << '\n';
    each(e, ans){
        cout << get<0>(e) << (get<2>(e)? " ^ " : " + ") << get<1>(e) << '\n';
    }
}