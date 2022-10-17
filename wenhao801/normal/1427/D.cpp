#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
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

int a[55], n;
vector <vector <int>> ans;
void op(vector <int> v) {
    static int tmp[55];
    int s = 0;
    for (auto i: v) {
        for (int j = 1; j <= i; j++) tmp[n - s - j + 1] = a[s + i - j + 1];
        s += i;
    }
    for (int i = 1; i <= n; i++) a[i] = tmp[i];
}

int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    int l = a[1], r = a[1]; bool at = 0;
    while (l != 1 || r != n) {
        at ^= 1;
        int aim = l == 1 ? (++r) : (--l);
        for (i = 1; i <= n && a[i] != aim; i++);
        vector <int> v;
        if ((a[1] < a[r - l]) == (aim == r)) {
            for (j = 1; j <= r - l; j++) v.push_back(1);
        }
        else v.push_back(r - l);
        if (i - (r - l)) v.push_back(i - (r - l));
        if (n - i) v.push_back(n - i);
        op(v); if (!at) reverse(v.begin(), v.end()); ans.push_back(v);
        reverse(a + 1, a + n + 1);
    }
    if (at) reverse(a + 1, a + n + 1);
    if (a[1] != 1) { vector <int> v; for (int i = 1; i <= n; i++) v.push_back(1); ans.push_back(v), op(v); }
    for (i = 1; i <= n; i++) assert(a[i] == i);
    assert(ans.size() <= n);
    printf("%d\n", ans.size());
    for (auto v: ans) {
        printf("%d ", v.size());
        for (auto i: v) printf("%d ", i);
        putchar('\n');
    }
    return 0;
}