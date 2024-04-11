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
    int T;
    cin >> T;
    rep(t, T){
        int N, M;
        cin >> N >> M;
        string s[N];
        rep(i, N) cin >> s[i];
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        rep(i, N) rep(j, M){
            if(s[i][j] != 'B') continue;
            rep(k, 4){
                int ni = i+dx[k], nj = j+dy[k];
                if(0 <= ni && ni < N && 0 <= nj && nj < M){
                    if(s[ni][nj] == '.') s[ni][nj] = '#';
                }
            }
        }
        bool able[N][M];
        fill(able[0], able[N], false);
        queue<pii> que;
        if(s[N-1][M-1] != '#') que.push(pii(N-1, M-1));
        while(!que.empty()){
            int x = que.front().first, y = que.front().second;
            que.pop();
            if(able[x][y]) continue;
            able[x][y] = true;
            rep(i, 4){
                int nx = x+dx[i], ny = y+dy[i];
                if(0 <= nx && nx < N && 0 <= ny && ny < M){
                    if(s[nx][ny] != '#'){
                        que.push(pii(nx, ny));
                    }
                } 
            }
        }
        bool res = true;
        rep(i, N) rep(j, M){
            if(s[i][j] == 'G' && !able[i][j]) res = false;
            if(s[i][j] == 'B' && able[i][j]) res = false;
        }
        if(res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}