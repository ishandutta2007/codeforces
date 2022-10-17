#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1001000, lim = 1e6;
int pr[MAXN], top; bool np[MAXN];
void sieve () {
    int i, j;
    for (i = 2; i <= lim; i++) {
        if (!np[i]) pr[++top] = i;
        for (j = 1; j <= top; j++) {
            if (i * pr[j] > lim) break;
            np[i * pr[j]] = 1;
            if (i % pr[j] == 0) break;
        }
    }
}

int n, d, a[MAXN];
vector <int> v;
int las[MAXN][3], nex[MAXN][3], cur[3];

int main () {
    sieve(); int T = read(); while (T--) {
        n = read(), d = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        long long ans = 0;
        for (i = 0; i < d; i++) {
            bool fir = 0;
            v.clear();
            for (j = n - i; j >= 1; j -= d) {
                int type;
                if (a[j] == 1) type = 1;
                else if (!np[a[j]]) type = 2;
                else type = 0;
                v.push_back(type);
            }
            reverse(v.begin(), v.end());
            int N = v.size();
            cur[0] = cur[1] = cur[2] = -1;
            for (j = 0; j < N; j++) {
                memcpy(las[j], cur, sizeof cur);
                cur[v[j]] = j;
            }
            cur[0] = cur[1] = cur[2] = N;
            for (j = N - 1; j >= 0; j--) {
                memcpy(nex[j], cur, sizeof cur);
                cur[v[j]] = j;
            }
            for (j = 0; j < N; j++) if (v[j] == 2) {
                int L = max(las[j][0], las[j][2]) + 1, R = min(nex[j][0], nex[j][2]) - 1;
                ans += 1ll * (j - L + 1) * (R - j + 1) - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}