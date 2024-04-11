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
    int Q; cin >> Q;

    vector<ll> a(Q+1), c(Q+1);
    vector<vector<int>> dp(20, vector<int>(Q+1, -1));

    cin >> a[0] >> c[0];

    rep2(v, 1, Q){
        int t; cin >> t;

        if(t == 1){
            int p; cin >> p >> a[v] >> c[v];
            
            dp[0][v] = p;
            rep2(i, 1, 19){
                if(dp[i-1][v] == -1) break;
                dp[i][v] = dp[i-1][dp[i-1][v]];
            }
        }
        else{
            int u; ll w; cin >> u >> w;

            int p = u, d = 0;

            rep3(i, 19, 0){
                int np = dp[i][p];
                if(np == -1) continue;
                if(a[np] > 0) p = np, d |= (1<<i);
            }

            ll ans = 0, r = w;
            //cout << d << ' ' << p << '\n';

            rep3(i, d, 0){
                p = u;
                rep(j, 20){
                    if((i>>j)&1) p = dp[j][p];
                }

                if(a[p] >= r){
                    ans += r*c[p], a[p] -= r, r = 0;
                    break;
                }
                else{
                    ans += a[p]*c[p], r -= a[p], a[p] = 0;
                }
            }

            cout << w-r << ' ' << ans << endl;
        }
    }
}