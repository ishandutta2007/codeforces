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

map<ll, int> mp;
map<ll, pll> mp2;

int rec(ll x){
    if(mp.count(x)) return mp[x];
    auto it = --mp2.upper_bound(x);
    auto [l, c] = (*it).second;
    return mp[x] = rec((x-(*it).first)%l);
}

int main(){
    int N; cin >> N;

    ll L = 0;
    rep(i, N){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            mp[L++] = x;
        }
        else{
            ll l, c; cin >> l >> c;
            mp2[L] = pll(l, c);
            L += l*c;
        }
    }

    int Q; cin >> Q;

    rep(i, Q){
        ll x; cin >> x; x--;
        cout << rec(x) << (i == Q-1? '\n' : ' '); 
    }
}