//
// Created by yamunaku on 2020/05/12.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

int main(){
    CFS;
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int vx[4] = {0, 1, 0, -1};
    int vy[4] = {1, 0, -1, 0};
    vector<vector<int>> p(n, vector<int>(m, -1));
    queue<pair<int, int>> que;
    rep(i, n){
        rep(j, m){
            rep(k, 4){
                int nx = i + vx[k];
                int ny = j + vy[k];
                if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                if(s[nx][ny] == s[i][j]){
                    p[i][j] = 0;
                    que.emplace(i, j);
                }
            }
        }
    }
    while(!que.empty()){
        auto now = que.front();
        que.pop();
        rep(k, 4){
            int nx = now.first + vx[k];
            int ny = now.second + vy[k];
            if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if(p[nx][ny] != -1) continue;
            if(s[nx][ny] != s[now.first][now.second]){
                int tt = p[now.first][now.second] + 1;
                p[nx][ny] = tt;
                que.emplace(nx, ny);
            }
        }
    }
    rep(t, q){
        int x, y;
        ll c;
        cin >> x >> y >> c;
        x--, y--;
        if(p[x][y] == -1){
            cout << s[x][y] << endl;
        }else if(c <= p[x][y]){
            cout << s[x][y] << endl;
        }else{
            if((p[x][y] - c) % 2){
                cout << 1 - (s[x][y] - '0') << endl;
            }else{
                cout << s[x][y] << endl;
            }
        }
    }
    return 0;
}