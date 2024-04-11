#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define ll long long
const int MAXN = 200200, lim = 1500;
char a[MAXN]; int n, s[MAXN];
ll ans = 0; unordered_map <ll, int> vis;

int b[MAXN], sb[MAXN], top;

int main () {
    scanf("%s", a + 1); n = strlen(a + 1);
    int i, j, k;
    for (i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - '0';
    for (k = 1; k <= n / lim + 1; k++) {
        vis.clear(); ll cur_i = 0, cur_j = 0;
        for (i = 1, j = 0; i <= n; i++) {
            while (s[i] - s[j] > lim) ++vis[!j ? 0 : (cur_j += k * (a[j] - '0') - 1)], ++j;
            ans += vis[cur_i += k * (a[i] - '0') - 1];
        }
    }
    top = 1;
    for (i = 1; i <= n; i++) {
        ++b[top];
        if (a[i] == '1') ++top;
    }
    ++b[top];
    if (top == 1) { puts("0"); return 0; }
    for (i = 1; i <= top; i++) sb[i] = sb[i - 1] + b[i];
    for (k = 1; k <= lim; k++) {
        for (i = 1; i + k <= top; i++) {
            int u = b[i] - 1, v = b[i + k] - 1;
            for (j = 0; j < k; j++) {
                if (j > u) break;
                int tmp = (1 + sb[i + k - 1] - sb[i] + j) % k;
                tmp = (k - tmp) % k;
                if (tmp > v) continue;
                ans += 1ll * ((u - j) / k + 1) * ((v - tmp) / k + 1);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}