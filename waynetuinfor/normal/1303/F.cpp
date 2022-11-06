#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define getchar gtx

inline int gtx() {
    const int N = 4096;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char c = 0; bool flag = false;
    while (c = getchar(), (c < '0' && c != '-') || c > '9') if (c == -1) return false;
    c == '-' ? (flag = true, x = 0) : (x = c - '0');
    while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    if (flag) x = -x;
    return true;
}

char buf[8192], stk[10], *pbuf = buf;

void Print(int x) {
    char *p = stk;
    while (x > 0) {
        *p++ = x % 10 + '0';
        x /= 10;
    }
    *p++ = '\n';
    while (p != stk) *pbuf++ = *--p;
    if (pbuf - buf >= 4096) {
        fwrite(buf, 1, pbuf - buf, stdout);
        pbuf = buf;
    }
}

int main() {
    int n, m, q; rit(n), rit(m), rit(q);
    vector<tuple<int, int, int>> v(q);
    for (int i = 0; i < q; ++i) {
        int x, y, c; rit(x), rit(y), rit(c);
        x--, y--;
        v[i] = make_tuple(x, y, c);
    }

    vector<vector<int>> a(n, vector<int>(m)), b = a;
    constexpr int kDx[4] = {1, 0, -1, 0};
    constexpr int kDy[4] = {0, 1, 0, -1};
    vector<int> uf(n * m), sz(n * m), ans(q);
    vector<tuple<int, int, int>> cg(q, make_tuple(-1, -1, -1));

    auto Solve = [&](int l, int r) {
        int c = get<2>(v[l]);
        for (int i = 0; i < n * m; ++i) sz[i] = 1, uf[i] = i;
        int ncomps = 0;

        function<int(int)> Find = [&](int x) {
            if (uf[x] == x) return x;
            return uf[x] = Find(uf[x]);
        };

        auto Merge = [&](int x, int y) {
            if ((x = Find(x)) == (y = Find(y))) return;
            if (sz[x] > sz[y]) swap(x, y);
            uf[x] = y;
            sz[y] += sz[x];
            --ncomps;
        };

        for (int i = l; i < r; ++i) {
            int x = get<0>(v[i]), y = get<1>(v[i]);
            if (a[x][y] != c) {
                cg[i] = make_tuple(x, y, a[x][y]);
                ncomps++;
                for (int k = 0; k < 4; ++k) {
                    int dx = kDx[k], dy = kDy[k];
                    if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= m) continue;
                    if (a[x + dx][y + dy] == c) Merge(x * m + y, (x + dx) * m + (y + dy));
                }
                a[x][y] = c;
            } 
            ans[i] += ncomps;
        }

        for (int i = 0; i < n * m; ++i) sz[i] = 1, uf[i] = i;
        ncomps = 0;
        copy(a.begin(), a.end(), b.begin());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (b[i][j] == c) continue;
                ncomps++;
                if (i > 0 && b[i - 1][j] == b[i][j]) Merge(i * m + j, (i - 1) * m + j);
                if (j > 0 && b[i][j - 1] == b[i][j]) Merge(i * m + j, i * m + (j - 1));
            }
        }
        for (int i = r - 1; i >= l; --i) {
            ans[i] += ncomps;
            if (get<0>(cg[i]) != -1) {
                int x, y, c; 
                tie(x, y, c) = cg[i];
                ncomps++;
                for (int k = 0; k < 4; ++k) {
                    int dx = kDx[k], dy = kDy[k];
                    if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= m) continue;
                    if (b[x + dx][y + dy] == c) Merge(x * m + y, (x + dx) * m + (y + dy));
                }
                b[x][y] = c;
            }
        }
    };

    for (int i = 0, j = 0; i < q; i = j) {
        for (j = i; j < q && get<2>(v[j]) == get<2>(v[i]); ++j);
        Solve(i, j);
    }
    for (int i = 0; i < q; ++i) Print(ans[i]);
    if (pbuf != buf) fwrite(buf, 1, pbuf - buf, stdout);
}