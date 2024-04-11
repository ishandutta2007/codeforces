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
    int T; cin >> T;

    while(T--){
        int N, M; cin >> N >> M;

        vector<vector<int>> c(N, vector<int>(M));
        vector<pair<int, pii>> ps;

        rep(i, N){
            rep(j, M){
                cin >> c[i][j];
                ps.eb(c[i][j], pii(i, j));
            }
        }

        sort(all(ps));

        vector<vector<int>> ans(N, vector<int>(M, -1));

        rep(i, M){
            auto [w, p] = ps[i];
            auto [x, y] = p;

            ans[x][i] = w, c[x][y] = -1;
        }

        rep(i, N){
            int ptr = 0;
            rep(j, M){
                if(ans[i][j] != -1) continue;

                while(c[i][ptr] == -1) ptr++;
                ans[i][j] = c[i][ptr++];
            }
        }

        rep(i, N){
            rep(j, M) cout << ans[i][j] << (j == M-1? '\n' : ' ');
        }
    }
}