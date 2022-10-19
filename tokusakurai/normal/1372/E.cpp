#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N, M;
    cin >> N >> M;
    int cnt[M+1][M+1][M+1];
    rep(i, M+1) rep(j, M+1) rep(k, M+1) cnt[i][j][k] = 0;
    rep(i, N){
        int k;
        cin >> k;
        rep(j, k){
            int L, R; cin >> L >> R; L--;
            rep2(m, L, R-1){
                rep2(l, 0, L){
                    rep2(r, R, M){
                        cnt[l][r][m]++;
                    }
                }
            }
        }
    }
    int dp[M+1][M+1];
    fill(dp[0], dp[M+1], 0);
    rep2(i, 1, M){
        rep2(j, 0, M-i){
            rep2(k, j, j+i-1){
                chmax(dp[j][j+i], dp[j][k]+dp[k+1][j+i]+(cnt[j][j+i][k]*cnt[j][j+i][k]));
            }
        }
    }
    cout << dp[0][M] << endl;
}