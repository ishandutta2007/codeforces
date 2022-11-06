#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

int n;
map <pair <int, int>, vector <int>> type;
bool vis[301];
int cnt[301];
int max_dist[301];
int maxd = 0;

int s, t, L, R;
vector <pair <pair <int, int>, int>> arr[2];
vector <int> flow;
vector <int> c;
vector <int> edge[1001];
vector <int> to;

void new_edge(int i, int j, int c) {
    //cout << i << '?' << j << endl;
    edge[i].pb(flow.size());
    flow.pb(0);
    edge[j].pb(flow.size());
    flow.pb(0);
    ::c.pb(c);
    ::c.pb(0);
    to.pb(j);
    to.pb(i);
}

int ver = 1;
int used[1001];

int dfs(int i, int f = 1e9) {
    if (used[i] == ver || f == 0)
        return 0;
    if (i == t) {
        //cout << "?" << f << endl;
        return f;
    }
    used[i] = ver;
    for (int j: edge[i]) {
        int ans = dfs(to[j], min(c[j] - flow[j], f));
        if (ans != 0) {
            flow[j] += ans;
            flow[j ^ 1] -= ans;
            return ans;
        }
    }
    return 0;
} 

int ans[301];
vector <int> circle[301];
int last[301][301];
int lastd[301];

void flow_find() {
    L = arr[0].size();
    R = arr[1].size();
    s = L + R;
    t = s + 1;
   // cout << "______" << endl;
    vector <pair <pair <int, int>, int>> mod; 
    for (int i = 0; i < L; ++i) {
        auto a = arr[0][i].x;
        for (int j = 0; j < R; ++j) {
            auto b = arr[1][j].x;
            if ((a.x == -1 || a.x == b.x) && (a.y == -1 || a.y == b.y)) {
                new_edge(i, j + L, 1e9);
                //cout << i << '?' << j << endl;
                if (a == b)  {
                    int f = min(arr[0][i].y, arr[1][j].y);
                    mod.pb({a, f});
                    arr[0][i].y -= f;
                    arr[1][j].y -= f;
                }
            }
        }
    }
    // cout << "L: ";
    // for (auto i: arr[0]) {
    //     cout << "(" << i.x.x << ' ' << i.x.y << ' ' << i.y << ") "; 
    // }
    // cout << endl;
    // cout << "R: ";
    // for (auto i: arr[1]) {
    //     cout << "(" << i.x.x << ' ' << i.x.y << ' ' << i.y << ") "; 
    // }
    // cout << endl;
    for (int i = 0; i < L; ++i) {
        new_edge(s, i, arr[0][i].y);
    }
    for (int i = 0; i < R; ++i) {
        new_edge(i + L, t, arr[1][i].y);
    }
    while (dfs(s)) {
        ++ver;
    }
    ++ver;
    for (int i = 0; i < L; ++i) {
        for (auto j: mod) {
            if (arr[0][i].x == j.x) {
                arr[0][i].y += j.y;
                for (int q: edge[i]) {
                    if (c[q] == 0) continue;
                    if (arr[1][to[q] - L].x == j.x) {
                        //cout << "OK" << endl;
                        flow[q] += j.y;
                        flow[q ^ 1] -= j.y;
                        break;
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j: edge[i + L]) {
            //cout << j << ' ' << to[j] << "!" << t << ' ' << c[j] << ' ' << flow[j] << endl;
            if (c[j] - flow[j] > 0 && c[j] != 0) {
                for (int i = 0; i <= t; ++i)
                    edge[i].clear();
                flow.clear();
                c.clear();
                to.clear();
                return;
            }
        }
    }
    // cout << "L: ";
    // for (auto i: arr[0]) {
    //     cout << "(" << i.x.x << ' ' << i.x.y << ' ' << i.y << ") "; 
    // }
    // cout << endl;
    // cout << "R: ";
    // for (auto i: arr[1]) {
    //     cout << "(" << i.x.x << ' ' << i.x.y << ' ' << i.y << ") "; 
    // }
    // cout << endl;
    for (int i = 0; i < R; ++i) {
        auto a = arr[1][i].x;
        for (int j: edge[i + L]) {
            if (c[j] != 0) continue;
            //cout << flow[j] << endl;
            auto b = arr[0][to[j]].x;
            if (a.x != 0) {
                for (int q = 0; q < -flow[j]; ++q) {
                    int id = type[b].back();
                    type[b].pop_back();
                    ans[id] = last[a.y][a.x - 1];
                    last[a.y][a.x] = id;
                    lastd[a.x] = id;
                }
            } else {
                for (int q = 0; q < -flow[j]; ++q) {
                    circle[a.y].pb(type[b].back());
                    type[b].pop_back();
                }
            }
        }
        if (a.x == 0) {
            for (int j = 0; j < circle[a.y].size(); j += a.y) {
                for (int q = 0; q < a.y; ++q) {
                    ans[circle[a.y][j + q]] = circle[a.y][j + ((q + 1) % a.y)];
                }
            }
            last[a.y][a.x] = circle[a.y][0];
            lastd[a.x] = circle[a.y][0];
        }
    }
    for (auto i: type) {
        for (int j: i.y) {
            //cout << i.x.x << ' ' << i.x.y << endl;
            assert(i.x.x != 0 || i.x.y == -1);
            if (i.x == make_pair(-1, -1) || i.x == make_pair(0, -1) || i.x == make_pair(0, 0)) {
                ans[j] = j;
            } else if (i.x.x == -1) {
                ans[j] = last[i.x.y][0];
            } else if (i.x.y == -1) {
                ans[j] = lastd[i.x.x - 1];
            } else {
                ans[j] = last[i.x.y][i.x.x - 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) 
        cout << ans[i] + 1 << ' ';
    cout << endl;
    exit(0);
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        int a, b;
        cin >> s1 >> s2;
        if (s1 == "?") {
            a = -1;
        } else {
            a = atoi(s1.c_str());
        }
        if (s2 == "?") {
            b = -1;
        } else {
            b = atoi(s2.c_str());
            vis[b] = true;
        }
        if (a == 0 && b != -1) {
            ++cnt[b];
        }
        if (a != -1 && b != -1) {
            chkmax(max_dist[b], a);
        }
        chkmax(maxd, a);
        type[{a, b}].pb(i);
    }
    for (auto i: type)
        arr[0].pb({i.x, i.y.size()});
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && j != i)
                continue;
            int need = max(j, ((cnt[j] - 1) / j + 1)  * j);
            arr[1].pb({{0, j}, need});
            if (j != i) {
                for (int k = 1; k <= max_dist[j]; ++k) {
                    arr[1].pb({{k, j}, 1});
                }
            } else {
                for (int k = 1; k <= maxd; ++k) {
                    arr[1].pb({{k, j}, 1});
                }
            }
        }
        if (arr[1].size() <= n) {
            flow_find();
        }
        arr[1].clear();
    }
    cout << -1 << endl;
}