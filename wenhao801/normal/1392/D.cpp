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

const int MAXN = 202000;
char a[MAXN];
vector <int> v;

int main() {
    int T = read(); while (T--) {
        int n = read(); scanf("%s", a);
        int i, j;
        char last = 'A'; int len = 0;
        for (i = 0; i < n; i++) {
            if (a[i] != last) {
                if (len) v.push_back(len);
                last = a[i]; len = 0;
            }
            ++len;
        }
        if (!(v.size() & 1) && !v.empty()) v[0] += len; else v.push_back(len);
        if (v.size() == 1) printf("%d\n", n / 3 + bool(n % 3));
        else {
            int ans = 0;
            for (auto i: v) ans += i / 3;
            printf("%d\n", ans);
        }
        v.clear();
    }
    return 0;
}