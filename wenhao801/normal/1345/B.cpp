#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int fun (int x) {
    int l = 0, r = 1e8;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ((3 * mid * mid + mid) / 2 <= x) ans = (3 * mid * mid + mid) >> 1, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

signed main () {
    int T = read();
    while (T--) {
        int n = read();
        int cnt = 0;
        int i, j;
        while (n >= 2) n -= fun(n), cnt++;
        cout << cnt << endl;
    }
    return 0;
}