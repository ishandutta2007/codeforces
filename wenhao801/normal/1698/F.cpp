#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 505;
int n, a[MAXN], b[MAXN];

map <pair <int, int>, int> visa, visb;
vector <pair <int, int>> ans;

void foo (int l, int r) {
    assert(a[l] == a[r]);
    ans.push_back({l, r});
    reverse(a + l, a + r + 1);
}

int vis[MAXN];

int main() {
    int T = read(); while (T--) {
        ans.clear();
        visa.clear(), visb.clear();

        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        for (i = 1; i <= n; i++) b[i] = read();
        if (a[1] != b[1] || a[n] != b[n]) {
            puts("No");
            continue;
        }
        for (i = 1; i < n; i++) visa[{min(a[i], a[i + 1]), max(a[i], a[i + 1])}]++;
        for (i = 1; i < n; i++) visb[{min(b[i], b[i + 1]), max(b[i], b[i + 1])}]++;
        if (visa != visb) { puts("No"); continue; }
        for (i = 2; i < n; i++) if (a[i] != b[i]) {
            for (j = i + 1; j <= n; j++) if (a[j] == a[i - 1] && a[j - 1] == b[i]) { foo(i - 1, j); break; }
            if (a[i] == b[i]) continue;
            for (j = 1; j <= n; j++) vis[j] = 0;
            for (j = i; j < n; j++) if (a[j] == a[i - 1] && a[j + 1] == b[i]) {
                for (int k = i - 1; k < j; k++) vis[a[k]] = k;
                for (int k = j + 1; k <= n; k++) if (vis[a[k]]) {
                    foo(vis[a[k]], k);
                    break;
                }
                break;
            }
            for (j = i + 1; j <= n; j++) if (a[j] == a[i - 1] && a[j - 1] == b[i]) { foo(i - 1, j); break; }
            assert(a[i] == b[i]);
        }

        puts("Yes"); printf("%d\n", int(ans.size()));
        for (auto i: ans) printf("%d %d\n", i.first, i.second);
    }
    return 0;
}