#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
#include <map>

int n;
int a[100100];
int s[100100];
map <int, bool> mp;
int main () {
    int T = read();
    while (T--) {
        int i, j, k;
        n = read(), k = read();
        mp.clear();
        for (i = 1; i <= n; i++) a[i] = read();
        for (i = 1; i <= n; i++) s[i] = s[i - 1] + (a[i] == k ? 1 : 0);
        if (!s[n]) { puts("no"); continue; }
        if (s[n] == n) { puts("yes"); continue; }
        bool f = false;
        int cnt = 0, cnts = 0;
        int las = -999242342;
        for (i = 1; i <= n; i++) {
            if (a[i] == k) {
                if ((i - las + 2) / 2 == cnts + 1) { f = true; break; }
                cnt = cnts = 0;
                las = i;
                mp.clear();
            }
            else if (!mp[a[i]]) {mp[a[i]] = true, cnt++; if (a[i] < k) cnts++;}
        }
        las = -998244353;
        for (i = 1; i <= n; i++) {
            if (a[i] > k) {
                if (i - las <= 2) {
                    f = true;
                    break;
                }
                if (a[i - 1] == k || a[i + 1 ] == k || a[i + 2] == k) { f = true; break; }
                if (i > 2 && a[i - 2] == k) { f = true; break; }
                las = i;
            }
        }
        if (f) puts("yes"); else puts("no");
    }
    return 0;
}