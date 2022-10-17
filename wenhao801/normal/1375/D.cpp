#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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

const int MAXN = 1010;
int n, a[MAXN];

int b[MAXN];
int mex () {
    for (int i = 0; i <= n; i++) b[i] = 0;
    for (int i = 1; i <= n; i++) ++b[a[i]];
    for (int i = 0; i <= n; i++) if (!b[i]) return i;
    return -1;
}
vector <int> ans;
void set (int x) { ans.push_back(x); a[x] = mex(); }

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        while (1) {
            int m = mex();
            if (m != n) set(m + 1);
            else {
                for (i = 1; i <= n; i++) if (a[i] != i - 1) break;
                if (i > n) break; else set(i);
            }
        }
        printf("%d\n", ans.size()); for (auto i: ans) printf("%d ", i); puts("");
        ans.clear();
    }
    return 0;
}