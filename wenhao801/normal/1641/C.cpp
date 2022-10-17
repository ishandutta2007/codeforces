#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
int n, q; set <int> s;

int t[MAXN];
inline int lowbit (int x) { return x & -x; }
inline int ask (int x) { int ret = 0; while (x) ret = max(ret, t[x]), x -= lowbit(x); return ret; }
void add (int x, int k) { while (x <= n) t[x] = max(t[x], k), x += lowbit(x); }

int main () {
    n = read(), q = read(); int i, j;
    for (i = 1; i <= n; i++) s.insert(i);
    while (q--) {
        int op = read();
        if (!op) {
            int l = read(), r = read(), x = read();
            if (!x) {
                auto it = s.lower_bound(l);
                while (it != s.end() && (*it) <= r) {
                    s.erase(it); it = s.lower_bound(l);
                }
            }
            else {
                add(r, l);
            }
        }
        else {
            int x = read(); auto it = s.find(x);
            if (it == s.end()) puts("NO");
            else {
                int L; if (it == s.begin()) L = 0; else { --it; L = *it; ++it; }
                ++it; int R = it == s.end() ? (n + 1) : (*it);
                ++L, --R; // printf("! %d %d\n", L, R);
                if (ask(R) >= L) puts("YES");
                else puts("N/A");
            }
        }
    }
    return 0;
}