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

template<typename T>
struct Grid{
    vector<T> S;
    vector<vector<int>> d;
    const int H, W;
    int K;

    Grid(const vector<T> &S, int K) : S(S), H(S.size()), W(S.front().size()), K(K) {
        d.resize(H);
        for(int i = 0; i < H; i++) d[i].resize(W);
    }

    bool in(int x, int y){
        return (0 <= x && x < H && 0 <= y && y < W);
    }

    int bfs(int sx, int sy, int tx = 0, int ty = 0){
        for(int i = 0; i < H; i++) fill(begin(d[i]), end(d[i]), INT_MAX/2);
        queue<pair<int, int>> que;
        d[sx][sy] = 0, que.emplace(sx, sy);
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        while(!que.empty() && K){
            auto [x, y] = que.front(); que.pop();
            K--;
            S[x][y] = '.';
            for(int k = 0; k < 4; k++){
                int nx = x+dx[k], ny = y+dy[k];
                if(!in(nx, ny) || S[nx][ny] == '#') continue;
                if(d[x][y]+1 < d[nx][ny]){
                    d[nx][ny] = d[x][y]+1, que.emplace(nx, ny);
                }
            }
        }
        return d[tx][ty];
    }
};

int main(){
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    K = -K;
    int sx = -1, sy = -1;
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '.'){
                K++, S[i][j] = 'X';
                sx = i, sy = j;
            }
        }
    }

    Grid<string> G(S, K);
    G.bfs(sx, sy);

    rep(i, H) cout << G.S[i] << '\n';
}