#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

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

const int inf = 1e9 + 7;
int n, k;

char a[100100] = {};

map <int, int> cnt;

signed main () {
    int T = read();
    while (T--) {
        n = read(), k = read();
        scanf("%s", a + 1);
        cnt.clear();
        int i, j;
        int Min = inf, Max = -inf;
        for (i = 1, j = 0; i <= n; i++){
            if (a[i] == '1') j--; else j++;
            cnt[j]++;
            Min = min(Min, j), Max = max(Max, j);
        }
        if (j == 0) {
            if (cnt[k] != 0) puts("-1");
            else puts("0"); continue;
        }
        
        int ans = 0, rua = j; if (k == 0) ans++;
        if (rua < 0) rua = -rua;
        for (i = -n; i <= n; i++) {
            if ((((j > 0) ^ (k < i)) || k == i) && (k % rua + rua) % rua == (i % rua + rua) % rua) ans += cnt[i];
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}