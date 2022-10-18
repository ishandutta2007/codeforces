#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
        sz = vector<int>(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }

    inline int size(int x) {
        return sz[get(x)];
    }

    inline bool root(int x) {
        return (x == get(x));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        for (int i = 0; i < h; i++) {
            cin >> s[i];
        }
        string ans = "YES";
        {
            dsu uf(h * w);
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] != '*') {
                        continue;
                    }
                    for (int ni = max(0, i - 1); ni <= min(h - 1, i + 1); ni++) {
                        for (int nj = max(0, j - 1); nj <= min(w - 1, j + 1); nj++) {
                            if (s[ni][nj] == '*') {
                                uf.unite(i * w + j, ni * w + nj);
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] == '*') {
                        if (uf.size(i * w + j) != 3) {
                            ans = "NO";
                        }
                    }
                }
            }
        }
        {
            dsu uf(h * w);
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] != '*') {
                        continue;
                    }
                    vector<int> di = {0, 1, 0, -1};
                    vector<int> dj = {1, 0, -1, 0};
                    for (int dir = 0; dir < 4; dir++) {
                        int ni = i + di[dir];
                        int nj = j + dj[dir];
                        if (0 <= ni && ni < h && 0 <= nj && nj < w && s[ni][nj] == '*') {
                            uf.unite(i * w + j, ni * w + nj);
                        }
                    }
                }
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] == '*') {
                        if (uf.size(i * w + j) != 3) {
                            ans = "NO";
                        }
                    }
                }
            }
        }
        {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j + 2 < w; j++) {
                    if (s[i][j] == '*' && s[i][j + 1] == '*' && s[i][j + 2] == '*') {
                        ans = "NO";
                    }
                }
            }
            for (int i = 0; i + 2 < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] == '*' && s[i + 1][j] == '*' && s[i + 2][j] == '*') {
                        ans = "NO";
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}