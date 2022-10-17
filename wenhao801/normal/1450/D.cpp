#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 300300;
int n, a[MAXN]; multiset <int> s;
bool ans[MAXN];

int main() {
    int T = read(); while (T--) {
        n = read(); int i, j; set <int> tmp;
        for (i = 1; i <= n; i++) a[i] = read(), tmp.insert(a[i]), ans[i] = 0, s.insert(a[i]);
        ans[1] = tmp.size() == n;
        int l = 1, r = n;
        for (i = 1; i < n; i++) {
            if (*s.begin() == i) ans[n - i + 1] = 1; else break;
            s.erase(s.find(i));
            if (a[l] == i) ++l;
            else if (a[r] == i) --r;
            else break;
        }
        for (i = 1; i <= n; i++) cout << ans[i];
        cout << endl; s.clear();
    }
    return 0;
}