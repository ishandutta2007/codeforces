#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const int mod = 998244353;
int cnk[maxn][maxn];

int main() {
    cnk[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        cnk[i][0] = 1;
        for (int j = 1; j < maxn; ++j)
            cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;
    }
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    int ans = cnk[n - 1][k];
    for (int i = 0; i < k; ++i) {
        ans = ans * 1ll * (m - 1) % mod;
    }
    ans = ans * 1ll * m % mod;
    printf("%d\n", ans);
}