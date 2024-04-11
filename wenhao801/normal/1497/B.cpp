#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

#include <map>
map <int, int> cnt; 
map <int, int>::iterator it;

int main () {
    int T = read();
    while (T--) {
        cnt.clear();
        int n = read(), m = read();
        int i, j;
        for (i = 1; i <= n; i++) {
            int x = read() % m;
            cnt[x]++;
        }
        int ans = 0;
        for (it = cnt.begin(); it != cnt.end(); ++it) {
            int val = (it) -> first, x = (it) -> second, y = cnt[(m - val) % m];
            if (!x && !y) continue;
            if (val == (m - val) % m) {
                ++ans;
                continue;
            }
            if (x < y) swap(x, y);
            if (x == y) ++ans;
            else ans += 1 + (x - y - 1);
            cnt[it -> first] = cnt[m - val] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}