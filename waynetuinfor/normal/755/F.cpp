#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int p[maxn], q[maxn];
bool v[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    int a = 0, b = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        int c = 0;
        for (int j = i; !v[j]; ++c, v[j] = true, j = p[j]);
        ++q[c];
        a += c / 2; b += c % 2;
    }
    bitset<maxn> dp; dp[0] = true;
    for (int i = 1; i <= n; ++i) if (q[i]) {
        int j = 0;
        while (q[i]) {
            int c = min((1 << j), q[i]);
            dp |= (dp << (c * i));
            q[i] -= c;
            ++j;
        } 
    }
    int maxc = min(k, a) * 2;
    int tk = k - min(k, a);
    maxc += min(tk, b);
    int minc = (dp[k] ? k : k + 1); 
    printf("%d %d\n", minc, maxc);
    return 0;
}