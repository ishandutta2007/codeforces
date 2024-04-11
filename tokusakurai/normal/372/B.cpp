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
    int N, M, Q; cin >> N >> M >> Q;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<vector<vector<int>>> dp(M, vector<vector<int>>(N+1, vector<int>(N+1, inf)));
    
    rep(i, M){
        rep(k, N+1){
            rep(j, k){
                int ptr = i;
                dp[i][j][k] = i+1;
                while(ptr >= 0){
                    int s = 0;
                    rep2(l, j, k-1) s += S[l][ptr]-'0';
                    if(s == 0) dp[i][j][k] = ptr--;
                    else break;
                }
            }
        }
    }
    
    vector<vector<vector<vector<int>>>> dp2(N+1, vector<vector<vector<int>>>(N+1, vector<vector<int>>(M+1, vector<int>(M+1, 0))));

    rep(j, N+1){
        rep(i, j){
            rep(k, M+1){
                rep2(l, k, M-1){
                    dp2[i][j][k][l+1] = dp2[i][j][k][l];
                    rep2(n, i+1, j){
                        rep2(m, i, n-1){
                            dp2[i][j][k][l+1] += l+1-max(k, dp[l][m][n]);
                        }
                    }
                }
            }
        }
    }

    while(Q--){
        int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry; lx--, ly--;
        cout << dp2[lx][rx][ly][ry] << '\n';
    }
}