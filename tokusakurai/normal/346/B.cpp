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
    string A, B, S; cin >> A >> B >> S;
    int N = sz(A), M = sz(B), K = sz(S);

    vector<vector<int>> nxt(K, vector<int>(26));

    rep(i, K){
        rep(j, 26){
            string T = S.substr(0, i);
            T += char('A'+j);
            rep3(k, i+1, 0){
                if(T.substr(i+1-k) == S.substr(0, k)){
                    nxt[i][j] = k;
                    break;
                }
            }
        }
    }

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(K, -inf)));
    vector<vector<vector<int>>> pre(N+1, vector<vector<int>>(M+1, vector<int>(K, -1)));
    vector<vector<vector<int>>> pre2(N+1, vector<vector<int>>(M+1, vector<int>(K, -1)));
    dp[0][0][0] = 0;

    rep(i, N+1){
        rep(j, M+1){
            rep(k, K){
                if(i+1 <= N){
                    if(chmax(dp[i+1][j][k], dp[i][j][k])) pre[i+1][j][k] = 1;
                }
                if(j+1 <= M){
                    if(chmax(dp[i][j+1][k], dp[i][j][k])) pre[i][j+1][k] = 2;
                }
                if(i+1 <= N && j+1 <= M){
                    if(A[i] != B[j]) continue;
                    int ni = i+1, nj = j+1, nk = nxt[k][A[i]-'A'];
                    if(nk < K){
                        if(chmax(dp[i+1][j+1][nk], dp[i][j][k]+1)){
                            pre[i+1][j+1][nk] = 3;
                            pre2[i+1][j+1][nk] = k;
                        }
                    }
                }
            }
        }
    }

    int pk = -1, ans = -1;
    rep(i, K){
        if(chmax(ans, dp[N][M][i])) pk = i;
    }

    if(ans == 0) {cout << "0\n"; return 0;}
    
    string T;
    int pi = N, pj = M;
    
    while(pi > 0 || pj > 0){
        int x = pre[pi][pj][pk];
        if(x == 1) pi--;
        else if(x == 2) pj--;
        else{
            pk = pre2[pi][pj][pk], pi--, pj--;
            T += A[pi];
        }
    }

    reverse(all(T));
    cout << T << '\n';
}