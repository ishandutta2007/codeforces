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
    int H, W, K; cin >> H >> W >> K;

    vector<vector<ll>> a(H, vector<ll>(W-1)), b(H-1, vector<ll>(W));

    rep(i, H){
        rep(j, W-1){
            cin >> a[i][j];
        }
    }

    rep(i, H-1){
        rep(j, W){
            cin >> b[i][j];
        }
    }

    if(K&1){
        rep(i, H){
            rep(j, W) cout << "-1" << (j == W-1? '\n' : ' ');
        }
        return 0;
    }

    K >>= 1;
    vector<vector<ll>> dp(H, vector<ll>(W, 0));
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    rep(i, K){
        vector<vector<ll>> tmp(H, vector<ll>(W, INF));

        rep(x, H){
            rep(y, W){
                rep(k, 4){
                    int nx = x+dx[k], ny = y+dy[k];
                    if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

                    ll c = (k == 0? b[x][y] : k == 1? a[x][y] : k == 2? b[x-1][y] : a[x][y-1]);

                    chmin(tmp[x][y], c+dp[nx][ny]);
                }
            }
        }

        swap(dp, tmp);
    }

    rep(i, H){
        rep(j, W) cout << dp[i][j]*2 << (j == W-1? '\n' : ' ');
    }
}