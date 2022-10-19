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
    int H, W;
    cin >> H >> W;
    string S[H];
    rep(i, H) cin >> S[i];
    int d[H][W];
    fill(d[0], d[H], inf);
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    queue<pii> que;
    rep(i, H){
        rep(j, W){
            rep(k, 4){
                int ni = i+dx[k], nj = j+dy[k];
                if(ni < 0 || ni >= H || nj < 0 || nj >= W || S[i][j] != S[ni][nj]) d[i][j] = 1;
            }
            if(d[i][j] == 1) que.emplace(i, j);
        }
    }
    while(!que.empty()){
        int i, j;
        tie(i, j) = que.front(), que.pop();
        rep(k, 4){
            int ni = i+dx[k], nj = j+dy[k];
            if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if(chmin(d[ni][nj], d[i][j]+1)) que.emplace(ni, nj);
        }
    }
    ll ans = 0;
    rep(i, H){
        rep(j, W) ans += d[i][j];
    }
    cout << ans << endl;
}