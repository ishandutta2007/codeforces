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

int main(){
    ll a; string S; cin >> a >> S;
    ll N = sz(S);

    vector<ll> s(N+1, 0);
    rep(i, N) s[i+1] = s[i]+(S[i]-'0');

    map<ll, ll> mp;

    rep(i, N+1){
        rep(j, i){
            mp[s[i]-s[j]]++;
        }
    }

    ll ans = 0;

    each(e, mp){
        if(a == 0){
            if(e.first == 0){
                ans += e.second*N*(N+1);
                ans -= e.second*e.second;
            }
        }
        else if(e.first > 0 && a%e.first == 0){
            ll x = a/e.first;
            if(mp.count(x)) ans += e.second*mp[x];
        }
    }

    cout << ans << '\n';
}