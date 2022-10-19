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
    int T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        ll l = 0, r = N;
        N--;
        while(r-l > 1){
            ll m = (l+r)/2;
            ll rem = N-m, now = 1;
            rep3(i, m, 1){
                ll tmp = now*i;
                rem -= tmp;
                if(rem <= 0) break;
                now *= 2;
            }
            if(rem <= 0) r = m;
            else l = m;
        }

        cout << r << '\n';
        vector<ll> ans(r, 0);
        ll rem = N-r, now = 1;
        rep3(i, r, 1){
            ll tmp = now*i;
            if(tmp < rem){
                rem -= tmp;
                ans[r-i] += now;
                now *= 2;
            }
            else{
                ans[r-i] += rem/i;
                rem %= i;
                if(rem > 0) ans[r-rem] += 1;
                break;
            }
        }

        rep(i, r) cout << ans[i] << ' '; cout << '\n';
    }
}