#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;


multiset <int> s;
int a[2020];
inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

int main () {
    int T = read();
    while (T--) {
        int n = read() << 1, i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        sort(a + 1, a + n + 1);
        for (i = 1; i < n; i++) {
            s.clear();
            int x = a[n]; for (j = 1; j < n; j++) if (j != i) s.insert(a[j]);
            while (!s.empty()) {
                multiset <int>::iterator it = s.end();
                --it; int mx = *it; s.erase(it);
                if (s.find(x - mx) == s.end()) break;
                s.erase(s.find(x - mx)); x = mx;
            }
            if (s.empty()) {
                puts("YES"); printf("%d\n%d %d\n", a[n] + a[i], a[n], a[i]);
                x = a[n]; for (j = 1; j < n; j++) if (j != i) s.insert(a[j]);
                while (!s.empty()) {
                    multiset <int>::iterator it = s.end();
                    --it; int mx = *it; s.erase(it);
                    if (s.find(x - mx) == s.end()) break;
                    s.erase(s.find(x - mx));
                    printf("%d %d\n", mx, x - mx); x = mx;
                }
                break;
            }
        }
        if (i == n) puts("NO");
    }
    return 0;
}