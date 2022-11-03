/**
 *    author:  otera    
**/
#include<iostream>
#include<string> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm> 
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
using namespace std;

// #define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, m;
// vector<vector<char>> s;
vector<string> s;

const int dx[8] = {-1,-1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

queue<P> que;
vector<vector<int>> dist;

// bool check(vector<vector<char>> f, int t) {
//     // queue<P> que;
//     // dist.assign(n + 2, vector<int>(m + 2, inf));
//     // rep(i, n + 2) {
//     //     rep(j, m + 2) {
//     //         // cerr << f[i][j];
//     //         if(f[i][j] == 'X') {
//     //             que.push({i, j});
//     //             dist[i][j] = 0;
//     //         }
//     //     }
//     //     // cerr << endl;
//     // }
//     // while(que.size()) {
//     //     P p = que.front(); que.pop();
//     //     int x = p.fr, y = p.sc;
//     //     rep(k, 8) {
//     //         int nx = x + dx[k], ny = y + dy[k];
//     //         if(0 <= nx and nx < n + 2 and 0 <= ny and ny < m + 2 and dist[nx][ny] == inf) {
//     //             que.push({nx, ny});
//     //             dist[nx][ny] = dist[x][y] + 1;
//     //             if(s[nx][ny] == '.' and dist[nx][ny] <= t) return false;
//     //             if(s[nx][ny] == 'X' and dist[nx][ny] > t) return false;
//     //         }
//     //     }
//     // }
//     vector<vector<int>> cnt(n + 3, vector<int>(m + 3, 0));
//     rep(i, n + 2) {
//         rep(j, m + 2) {
//             if(i - t >= 0 and j - t >= 0 and i + t < n + 2 and j + t < m + 2) {
//                 if(f[i][j] == 'X') {
//                     cnt[i - t][j - t] ++;
//                     cnt[i - t][j + t + 1] --;
//                     cnt[i + t + 1][j - t] --;
//                     cnt[i + t + 1][j + t + 1] ++;
//                 }
//             }
//         }
//     }
//     rep(i, n + 3) {
//         rep(j, m + 2) {
//             cnt[i][j + 1] += cnt[i][j];
//         }
//     }
//     rep(i, n + 2) {
//         rep(j, m + 3) {
//             cnt[i + 1][j] += cnt[i][j];
//         }
//     }
//     rep(i, n + 2) {
//         rep(j, m + 2) {
//             if(s[i][j] == '.') {
//                 if(cnt[i][j] != 0) return false;
//             } else {
//                 if(cnt[i][j] == 0) return false;
//             }
//         }
//     }
//     return true;
// }

void solve() {
	cin >> n >> m;
    s.resize(n + 2);
    s[0] = string(m + 2, '.');
    s[n + 1] = string(m + 2, '.');
    // s.resize(n + 2);
    vector<string> raw(n);
    rep(i, n) {
        cin >> raw[i];
    }
    rep(i, n) {
        // rep(j, m) {
        //     s[i + 1][j + 1] = raw[i][j];
        // }
        string ret = ".";
        ret += raw[i];
        ret += '.';
        s[i + 1] = ret;
    }
    vector<vector<int>> sum(n + 3, vector<int>(m + 3, 0));
    rep(i, n + 2) {
        rep(j, m + 2) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (s[i][j] == 'X');
        }
    }
    auto calc = [&](int a, int b, int c, int d) {
        return sum[c + 1][d + 1] - sum[c + 1][b] - sum[a][d + 1] + sum[a][b];
    };
    auto make = [&](int t) {
        vector<string> ret(n, string(m, '.'));
        for(int i = t; i < n + 2 - t; ++ i) {
            for(int j = t; j < m + 2 - t; ++ j) {
                if(i - t >= 0 and j - t >= 0 and i + t < n + 2 and j + t < m + 2) {
                    if(calc(i - t, j - t, i + t, j + t) == (2 * t + 1) * (2 * t + 1)) {
                        if(i - 1 >= 0 and j - 1 >= 0) ret[i - 1][j - 1] = 'X';
                    }
                }
            }
        }
        return ret;
    };
    vector<vector<int>> cnt(n + 3, vector<int>(m + 3, 0));
    auto check = [&](int t) {
        cnt.assign(n + 3, vector<int>(m + 3, 0));
        for(int i = t; i < n + 2 - t; ++ i) {
            for(int j = t; j < m + 2 - t; ++ j) {
                if(i - t >= 0 and j - t >= 0 and i + t < n + 2 and j + t < m + 2) {
                    if(calc(i - t, j - t, i + t, j + t) == (2 * t + 1) * (2 * t + 1)) {
                        cnt[i - t][j - t] ++;
                        cnt[i - t][j + t + 1] --;
                        cnt[i + t + 1][j - t] --;
                        cnt[i + t + 1][j + t + 1] ++;
                    }
                }
            }
        }
        rep(i, n + 3) {
            rep(j, m + 2) {
                cnt[i][j + 1] += cnt[i][j];
            }
        }
        rep(i, n + 2) {
            rep(j, m + 3) {
                cnt[i + 1][j] += cnt[i][j];
            }
        }
        rep(i, n + 2) {
            rep(j, m + 2) {
                if(s[i][j] == '.') {
                    if(cnt[i][j] != 0) return false;
                } else {
                    if(cnt[i][j] == 0) return false;
                }
            }
        }
        return true;
    };
    int ok = 0, ng = min(n, m);
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    auto ans = make(ok);
    rep(i, n) {
        cout << ans[i] << "\n";
        // rep(j, m) {
        //     cout << ans[i + 1][j + 1];
        // }
        // cout << endl;
    }
    // queue<P> que;
    // vector<vector<int>> dist(n + 2, vector<int>(m + 2, inf));
    // rep(i, n + 2) {
    //     rep(j, m + 2) {
    //         if(s[i][j] == '.') {
    //             dist[i][j] = 0;
    //             que.push({i, j});
    //         }
    //     }
    // }
    // while(que.size()) {
    //     P p = que.front(); que.pop();
    //     int x = p.fr, y = p.sc;
    //     rep(k, 8) {
    //         int nx = x + dx[k], ny = y + dy[k];
    //         if(0 <= nx and nx < n + 2 and 0 <= ny and ny < m + 2 and dist[nx][ny] == inf) {
    //             dist[nx][ny] = dist[x][y] + 1;
    //             que.push({nx, ny});
    //         }
    //     }
    // }
    // int ma = 0;
    // rep(i, n + 2) {
    //     rep(j, m + 2) {
    //         chmax(ma, dist[i][j]);
    //     }
    // }
    // if(ma == 0) {
    //     cout << 0 << endl;
    //     rep(i, n) {
    //         rep(j, m) {
    //             cout << s[i + 1][j + 1];
    //         }
    //         cout << endl;
    //     }
    //     return;
    // }
    // vector<vector<char>> f(n + 2, vector<char>(m + 2, '.'));
    // vector<vector<int>> dist2(n + 2, vector<int>(m + 2, inf));
    // rep(i, n + 2) {
    //     rep(j, m + 2) {
    //         if(dist[i][j] == ma) {
    //             // cerr << i << " " << j << endl;
    //             f[i][j] = 'X';
    //             dist2[i][j] = 0;
    //             que.push({i, j});
    //         }
    //     }
    // }
    // while(que.size()) {
    //     P p = que.front(); que.pop();
    //     int x = p.fr, y = p.sc;
    //     rep(k, 8) {
    //         int nx = x + dx[k], ny = y + dy[k];
    //         if(0 <= nx and nx < n + 2 and 0 <= ny and ny < m + 2 and dist2[nx][ny] == inf) {
    //             dist2[nx][ny] = dist2[x][y] + 1;
    //             que.push({nx, ny});
    //         }
    //     }
    // }
    // // cerr << ma << endl;
    // bool ok = 1;
    // rep(i, n + 2) {
    //     rep(j, m + 2) {
    //         if(dist2[i][j] <= ma - 1 and s[i][j] == 'X') continue;
    //         if(dist2[i][j] >= ma and s[i][j] == '.') continue;
    //         ok = 0;
    //     }
    // }
    // if(!ok) {
    //     cout << 0 << endl;
    //     rep(i, n) {
    //         rep(j, m) {
    //             cout << s[i + 1][j + 1];
    //         }
    //         cout << endl;
    //     }
    //     return;
    // }
    // cout << ma - 1 << endl;
    // rep(i, n) {
    //     rep(j, m) {
    //         cout << f[i + 1][j + 1];
    //     }
    //     cout << endl;
    // }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}