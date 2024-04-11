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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    
    vector<vector<int>> idx(H), idy(W);
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '#') idx[i].eb(j);
        }
    }
    rep(j, W){
        rep(i, H){
            if(S[i][j] == '#') idy[j].eb(i);
        }
    }

    rep(i, H){
        rep(j, sz(idx[i])-1){
            if(idx[i][j]+1 != idx[i][j+1]) {cout << -1 << '\n'; return 0;}
        }
    }
    rep(i, W){
        rep(j, sz(idy[i])-1){
            if(idy[i][j]+1 != idy[i][j+1]) {cout << -1 << '\n'; return 0;}
        }
    }

    vector<vector<bool>> a(H, vector<bool>(W, false));

    rep(i, H){
        rep(j, W){
            if(S[i][j] == '#') a[i][j] = true;
            if(idx[i].empty() && idy[j].empty()) a[i][j] = true;
        }
    }

    rep(i, H){
        bool flag = false;
        rep(j, W){
            if(a[i][j]) flag = true;
        }
        if(!flag) {cout << -1 << '\n'; return 0;}
    }
    rep(j, W){
        bool flag = false;
        rep(i, H){
            if(a[i][j]) flag = true;
        }
        if(!flag) {cout << -1 << '\n'; return 0;}
    }
    
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

    int ans = 0;
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '.') continue;
            ans++;
            queue<pii> que;
            que.emplace(i, j);
            S[i][j] = '.';
            while(!que.empty()){
                auto [x, y] = que.front(); que.pop();
                rep(k, 4){
                    int nx = x+dx[k], ny = y+dy[k];
                    if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if(S[nx][ny] == '#'){
                        S[nx][ny] = '.';
                        que.emplace(nx, ny);
                    } 
                }
            }
        }
    }

    cout << ans << '\n';

    /*
    vector<vector<bool>> a(H, vector<bool>(W, true));
    rep(i, H){
        int l = 0, r = sz(idx[i]);
        rep(j, W){
            if(S[i][j] == '#') r--;
            if(!idx.empty()){
                if(idx[i].back() > j+r) a[i][j] = false;
                if(idx[i].front() < j-l) a[i][j] = false;
            }
            if(S[i][j] == '#') l++;
        }
    }
    rep(j, W){
        int l = 0, r = sz(idy[j]);
        rep(i, H){
            if(S[i][j] == '#') r--;
            if(!idy.empty()){
                if(r > 0 && idy[i].back() > i+r) a[i][j] = false;
                if(l > 0 && idy[i].front() < i-l) a[i][j] = false;
            }
            if(S[i][j] == '#') l++;
        }
    }

    vector<int> L(H, inf), R(H, -inf), U(W, inf), D(W, -inf);
    rep(i, H){
        bool flag = false;
        rep(j, W){
            if(a[i][j]) flag = true, chmin(L[i], j), chmax(R[i], j);
        }
        if(!flag) {cout << -1 << '\n'; return 0;}
    }
    rep(j, W){
        bool flag = false;
        rep(i, H){
            if(a[i][j]) flag = true, chmin(U[j], i), chmax(D[j], i);
        }
        if(!flag) {cout << -1 << '\n'; return 0;}
    }

    int ans = 0;
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '.') continue;
            ans++;
            queue<pii> que;
            que.emplace(i, j);
            S[i][j] = '.';
            while(!que.empty()){
                auto [x, y] = que.front(); que.pop();
                if(y < W-1 && R[x] > y+1 && S[x][y+1] == '#'){
                    S[x][y+1] = '.', que.emplace(x, y+1);
                }
                if(y > 0 && L[x] < y-1 && S[x][y-1] == '#'){
                    S[x][y-1] = '.', que.emplace(x, y-1);
                }
                if(x < H-1 && D[y] > x+1 && S[x+1][y] == '#'){
                    S[x+1][y] = '.', que.emplace(x+1, y);
                }
                if(x > 0 && U[y] < x-1 && S[x-1][y] == '#'){
                    S[x-1][y] = '.', que.emplace(x-1, y);
                }
            }
        }
    }

    cout << ans << '\n';
    rep(i, 3){
        rep(j, 3) cout << a[i][j]; cout << '\n';
    }
    */
}