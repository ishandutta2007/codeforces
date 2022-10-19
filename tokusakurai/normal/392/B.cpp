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
    vector<vector<ll>> c(3, vector<ll>(3));

    rep(i, 3){
        rep(j, 3){
            cin >> c[i][j];
        }
    }

    int N; cin >> N;

    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(3, vector<ll>(3, 0)));
    
    rep2(i, 1, N){
        rep(j, 3){
            rep(k, 3){
                if(j == k) continue;
                int l = 3-j-k;

                dp[i][j][k] = dp[i-1][j][l]+c[j][k]+dp[i-1][l][k];
                chmin(dp[i][j][k], dp[i-1][j][k]+c[j][l]+dp[i-1][k][j]+c[l][k]+dp[i-1][j][k]);
            }
        }

        rep(t, 3){
            rep(j, 3){
                rep(k, 3){
                    chmin(dp[i][j][k], dp[i][j][t]+dp[i][t][k]);
                }
            }
        }
    }
    
    cout << dp[N][0][2] << '\n';
}