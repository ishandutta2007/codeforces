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
    int N, M; cin >> N >> M;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    int K = 0;
    int sx = 0, sy = 0;

    vector<int> xs(8), ys(8);

    rep(i, N){
        rep(j, M){
            if(S[i][j] == 'S') sx = i, sy = j;
            if('1' <= S[i][j] && S[i][j] <= '8'){
                int x = S[i][j]-'1';
                chmax(K, x+1);
                xs[x] = i, ys[x] = j;
            }
        }
    }

    vector<int> v(K);
    rep(i, K) cin >> v[i];

    int L = K;

    rep(i, N){
        rep(j, M){
            if(S[i][j] == 'B'){
                xs[L] = i, ys[L] = j;
                L++;
            }
        }
    }

    //cout << K << ' ' << L << '\n';

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(1<<L, inf)));

    vector<vector<int>> memo(N, vector<int>(M, 0));
    
    rep(i, N){
        rep(j, M){
            rep(k, L){
                if(xs[k] == i && j < ys[k]){
                    memo[i][j] |= (1<<k);
                }
            }
        }
    }
    
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    queue<tuple<int, int, int>> que;
    dp[sx][sy][0] = 0;
    que.emplace(sx, sy, 0);
    
    while(!que.empty()){
        auto [x, y, s] = que.front(); que.pop();

        rep(k, 4){
            int nx = x+dx[k], ny = y+dy[k];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || (S[nx][ny] != '.' && S[nx][ny] != 'S')) continue;

            int ns = s;
            if(k == 0) ns ^= memo[x][y];
            if(k == 2) ns ^= memo[nx][ny];

            if(chmin(dp[nx][ny][ns], dp[x][y][s]+1)){
                que.emplace(nx, ny, ns);
            }
        }
    }

    int ans = 0;

    rep(k, 1<<L){
        if(k>>K) continue;
        int score = 0;
        rep(l, K){
            if((k>>l)&1) score += v[l];
        }
        chmax(ans, score-dp[sx][sy][k]);
    }

    cout << ans << '\n';
}