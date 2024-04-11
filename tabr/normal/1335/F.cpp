#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    string ch = "UDLR";
    vector<int> dh = {-1, 1, 0, 0}, dw = {0, 0, -1, 1};
    while (tt--) {
        int h, w;
        cin >> h >> w;
        vector<string> c(h), s(h);
        vector<int> g(h * w);
        vector<vector<int>> r(h * w);
        for (int i = 0; i < h; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < h; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < 4; k++) {
                    if (s[i][j] == ch[k]) {
                        g[i * w + j] = i * w + j + dh[k] * w + dw[k];
                        r[g[i * w + j]].emplace_back(i * w + j);
                    }
                }
            }
        }
        int a = 0, b = 0;
        int lsz = -1, lroot = -1;
        vector<int> was(h * w, -1), t(h * w, -1);
        function<void(int, int)> loop = [&](int v, int id) {
            if (was[v] != -1) {
                lsz = id - was[v];
                lroot = v;
                return;
            }
            was[v] = id;
            loop(g[v], id + 1);
        };
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (was[i * w + j] == -1) {
                    lsz = lroot = -1;
                    loop(i * w + j, 0);
                    a += lsz;
                    vector<bool> bl(lsz);
                    queue<int> que;
                    que.push(lroot);
                    int col = 0;
                    while (que.size()) {
                        for (int i = que.size(); i > 0; i--) {
                            int v = que.front();
                            que.pop();
                            if (c[v / w][v % w] == '0') {
                                bl[col] = true;
                            }
                            t[v] = col;
                            was[v] = 1;
                            for (int to : r[v]) {
                                if (t[to] == -1) {
                                    que.push(to);
                                }
                            }
                        }
                        col = (col + 1) % lsz;
                    }
                    for (int i = 0; i < lsz; i++) {
                        if (bl[i]) {
                            b++;
                        }
                    }
                }
            }
        }
        cout << a << " " << b << '\n';
    }
    return 0;
}