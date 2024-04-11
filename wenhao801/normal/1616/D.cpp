#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 50050;
int n, a[MAXN], f[MAXN];

deque <int> q;
inline int val (int x) { return f[max(0, x - 2)] - x; }

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        j = read(); for (i = 1; i <= n; i++) a[i] -= j;
        int las2 = 0, las3 = 0;
        for (i = 1; i <= n; i++) {
            if (i >= 2 && a[i] + a[i - 1] < 0) las2 = i;
            if (i >= 3 && a[i] + a[i - 1] + a[i - 2] < 0) las3 = i - 1;
            // printf("%d %d\n", las2, las3);
            while (!q.empty() && q.front() < max(las2, las3)) q.pop_front();
            f[i] = max(f[i - 1], f[max(0, i - 2)] + 1);
            if (!q.empty()) f[i] = max(f[i], i + val(q.front()) + 1);
            while (!q.empty() && val(q.back()) < val(i)) q.pop_back();
            q.push_back(i);
            // cout << f[i] << endl;
        }
        q.clear(); printf("%d\n", f[n]);
        for (i = 0; i <= n; i++) f[i] = 0;
    }
    return 0;
}