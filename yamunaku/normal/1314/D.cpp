//
// Created by yamunaku on 2020/02/24.
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
    int n, k;
    cin >> n >> k;
    k >>= 1;
    int d[84][84];
    rep(i, 84){
        rep(j, 84){
            if(i == j) d[i][j] = 0;
            else d[i][j] = 100000000;
        }
    }
    rep(i, n){
        rep(j, n){
            cin >> d[i][j];
        }
    }
    int e[84][84][5], id[84][84][5];
    rep(i, 84) rep(j, 84) rep(t, 5) e[i][j][t] = 100000000, id[i][j][t] = -1;
    rep(i, 84){
        rep(j, 84){
            rep(x, 84){
                if(x == i || x == j) continue;
                int dist = d[i][x] + d[x][j];
                int idx = x;
                rep(t, 5){
                    if(dist < e[i][j][t]){
                        swap(dist, e[i][j][t]);
                        swap(idx, id[i][j][t]);
                    }
                }
            }
        }
    }
    int sel[5];
    int used[84];
    int nd[5][5];
    int dis[5][6];
    int ans = IINF;
    for(sel[1] = sel[0] + 1; sel[1] < 81; sel[1]++){
        for(sel[2] = sel[1] + 1; sel[2] < 82; sel[2]++){
            for(sel[3] = sel[2] + 1; sel[3] < 83; sel[3]++){
                for(sel[4] = sel[3] + 1; sel[4] < 84; sel[4]++){
                    used[sel[0]] = used[sel[1]] = used[sel[2]] = used[sel[3]] = used[sel[4]] = 1;
                    rep(i, 5){
                        rep(j, 5){
                            nd[i][j] = 100000000;
                            rep(t, 5){
                                if(used[id[sel[i]][sel[j]][t]]) continue;
                                nd[i][j] = e[sel[i]][sel[j]][t];
                                break;
                            }
                        }
                    }
                    dis[0][0] = 0, dis[1][0] = dis[2][0] = dis[3][0] = dis[4][0] = IINF;
                    repl(t, 1, k+1){
                        dis[0][t] = dis[1][t] = dis[2][t] = dis[3][t] = dis[4][t] = IINF;
                        rep(i, 5){
                            rep(j, 5){
                                dis[i][t] = min(dis[i][t], dis[j][t - 1] + nd[j][i]);
                            }
                        }
                    }
                    ans = min(ans, dis[0][k]);
                    used[sel[0]] = used[sel[1]] = used[sel[2]] = used[sel[3]] = used[sel[4]] = 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}