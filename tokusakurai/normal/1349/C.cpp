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
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    vector<vector<int>> a(H, vector<int>(W));
    rep(i, H){
        rep(j, W){
            a[i][j] = S[i][j]-'0';
            if((i+j)&1) a[i][j] ^= 1;
        }
    }

    vector<vector<ll>> d(H, vector<ll>(W, INF));
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    queue<pii> que;
    rep(i, H) rep(j, W){
        rep(k, 4){
            int ni = i+dx[k], nj = j+dy[k];
            if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            bool flag = true;
            if(a[i][j] != a[ni][nj]){
                d[i][j] = 0, que.emplace(i, j);
                break;
            }
        }
    }

    while(!que.empty()){
        auto [i, j] = que.front(); que.pop();
        rep(k, 4){
            int ni = i+dx[k], nj = j+dy[k];
            if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if(chmin(d[ni][nj], d[i][j]+1)) que.emplace(ni, nj);
        }
    }

    while(Q--){
        int x, y; ll t; cin >> x >> y >> t; x--, y--;
        int ans = a[x][y];
        if(t >= d[x][y]){
            if((t-d[x][y])&1) ans ^= 1;
        }
        if((x+y)&1) ans ^= 1;
        cout << ans << '\n';
    }
}