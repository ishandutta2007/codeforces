#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 500500;
int n, a[MAXN], top, add;

#define pii pair<int, int>
#define fr first
#define se second
map <int, int> vis;
vector <pii> ans1; vector <int> ans2;
#define size(v) (int(v.size()))

int main () {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T = read();
    while (T--) {
        n = read(); int i, j;
        while (n--) {
            int x = read();
            // printf("x = %d\n", x);
            if (!vis[x]) { a[++top] = x; vis[x] = top; continue; }
            else {
                // printf("! %d %d\n", vis[x] - 1, top + vis[x] - 1);
                // printf("! %d %d %d %d\n", add, top, vis[x] - (vis[x] - 1) + top - 1 + add, vis[x]);
                for (i = vis[x] - 1; i >= 1; i--) {
                    ans1.push_back(pii(vis[x] - i + top - 1 + add, a[i]));
                }
                for (i = vis[x] + 1; i <= top; i++) {
                    ans1.push_back(pii(add + top + 1 + 2 * (vis[x] - 1) + i - vis[x] - 1, a[i]));
                }
                for (i = vis[x] - 1; i >= 1; i--) {
                    ans1.push_back(pii(add + top + 1 + 2 * (vis[x] - 1) + top - vis[x] + vis[x] - 1 - i, a[i]));
                }
                ans2.push_back(top + vis[x] - 1);
                add += 2 * (top + vis[x] - 1);
                for (i = vis[x]; i < top; i++) vis[a[i + 1]] = top - vis[a[i + 1]] + vis[x], a[i] = a[i + 1];
                --top; reverse(a + vis[x], a + top + 1); vis[x] = 0;
            }
            // for (int i = 1; i <= top; i++) cout << a[i] << ' '; cout << endl;
            // cout << vis[3] << endl;
        }
        if (top) puts("-1");
        else {
            printf("%d\n", size(ans1));
            for (auto i: ans1) printf("%d %d\n", i.fr, i.se);
            printf("%d\n", size(ans2));
            for (auto i: ans2) printf("%d ", i << 1);
            putchar('\n');
        }
        top = add = 0, vis.clear(), ans1.clear(), ans2.clear();
    }
    return 0;
}