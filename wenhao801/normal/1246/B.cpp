#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
int n, K, p[MAXN], top, np[MAXN];

const int b = 998244353, mod = 1e9 + 9;
const int b2 = 10007, mod2 = 998244353;

#define pii pair<int, int>
#define fr first
#define se second
map <pii, int> mp[100100];

int main () {
    n = read(), K = read();
    int i, j;
    for (i = 2; i <= 100000; i++) {
        if (np[i]) continue;
        p[++top] = i;
        for (j = i + i; j <= 100000; j += i) np[j] = 1;
    }
    long long ans = 0;
    for (i = 1; i <= n; i++) {
        int x = read(); pii now = make_pair(0, 0), inow = make_pair(0, 0);
        for (j = 1; p[j] <= 317; j++) {
            int cur = 0; while (x % p[j] == 0) x /= p[j], ++cur;
            cur %= K;
            now = make_pair((1ll * now.fr * b + cur) % mod, (1ll * now.se * b2 + cur) % mod2);
            inow = make_pair((1ll * inow.fr * b + (K - cur) % K) % mod, (1ll * inow.se * b2 + (K - cur) % K) % mod2);
            // cout << now.fr << ' ' << inow.fr << endl;
        }
        // cout << endl;
        // printf("%d %d | %d %d\n", now.fr, now.se, inow.fr, inow.se);
        // if (mp[x][inow]) printf("! %d\n", x);
        if (x == 1 || K == 2) ans += mp[x][inow];
        ++mp[x][now];
    }
    printf("%lld\n", ans);
    return 0;
}