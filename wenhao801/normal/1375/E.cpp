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

#define pii pair<int, int>
#define fr first
#define se second

const int MAXN = 1010;
int n; pii a[MAXN];
vector <pii> ans, tmp;

bool cmp (pii x, pii y) { return x.fr == y.fr ? (x.se < y.se) : (x.fr < y.fr); }

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i].fr = read(), a[i].se = i;
    for (i = n; i >= 1; i--) {
        tmp.clear();
        for (j = 1; j < i; j++) if (a[j].fr > a[i].fr) tmp.push_back(a[j]);
        sort(tmp.begin(), tmp.end());
        for (auto j: tmp) ans.emplace_back(j.se, i);
    }
    printf("%d\n", ans.size());
    for (auto i: ans) printf("%d %d\n", i.fr, i.se);
    return 0;
}