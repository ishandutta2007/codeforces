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

map <int, int> vis;
vector <int> v;
int main () {
    int T = read(); while (T--) {
        int n = read(), m = read(), i, j;
        vis.clear();
        for (i = 1; i <= n; i++) ++vis[read()];
        int mex = 0, _m = m;
        while (vis.count(mex)) ++mex;
        while (_m && mex < n) {
            --_m; ++mex;
            while (mex < n && vis.count(mex)) ++mex;
        }
        if (_m) { puts("0"); continue; }
        v.clear(); for (auto i: vis) if (i.first >= mex) v.push_back(i.second);
        sort(v.begin(), v.end());
        int ans = 0;
        for (auto i: v) {
            if (i <= m) m -= i; else m = 0, ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}