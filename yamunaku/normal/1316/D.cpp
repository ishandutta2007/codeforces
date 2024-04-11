//
// Created by yamunaku on 2020/03/04.
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
    int n;
    scanf("%d", &n);
    mti x(n, vi(n)), y(n, vi(n));
    rep(i, n){
        rep(j, n){
            scanf("%d %d", &x[i][j], &y[i][j]);
            x[i][j]--, y[i][j]--;
        }
    }
    vi vx = {-1, 1, 0, 0};
    vi vy = {0, 0, -1, 1};
    string dir = "UDLR";
    string dir2 = "DURL";
    vector<string> ans(n, string(n, '*'));
    vector<pair<int, int>> xcell;
    rep(i, n){
        rep(j, n){
            if(x[i][j] == i && y[i][j] == j){
                ans[i][j] = 'X';
                xcell.emplace_back(i, j);
            }
            if(x[i][j] < 0){
                rep(k, 4){
                    int nx = i + vx[k];
                    int ny = j + vy[k];
                    if(nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
                    if(x[nx][ny] < 0){
                        ans[i][j] = dir[k];
                        goto next;
                    }
                }
                cout << "INVALID" << endl;
                return 0;
                next:;
            }
        }
    }
    for(auto &stp:xcell){
        queue<pair<int, int>> q;
        q.emplace(stp.first, stp.second);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            rep(k, 4){
                int nx = p.first + vx[k];
                int ny = p.second + vy[k];
                if(nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
                if(x[nx][ny] != stp.first || y[nx][ny] != stp.second) continue;
                if(ans[nx][ny] != '*') continue;
                ans[nx][ny] = dir2[k];
                q.emplace(nx, ny);
            }
        }
    }
    rep(i, n){
        rep(j, n){
            if(ans[i][j] == '*'){
                cout << "INVALID" << endl;
                return 0;
            }
        }
    }
    cout << "VALID" << endl;
    rep(i, n){
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}