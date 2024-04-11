#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
char s[maxn];
int z[maxn], c[maxn];
bool can[maxn];

int main() {
    int n; scanf("%d", &n);
    fill_n(can, n, true);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int k = strlen(s);
        for (int j = 0; j < k; ++j) {
            c[i] += s[j] == '(' ? 1 : -1;
            if (c[i] < 0) can[i] = false;
        }
        bool r = true; int tc = 0;
        for (int j = k - 1; j >= 0; --j) {
            tc += s[j] == ')' ? 1 : -1;
            if (tc < 0) r = false;
        }
        if (r && c[i] <= 0) ++z[-c[i]];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) if (can[i]) ans += z[c[i]];
    printf("%lld\n", ans);
    return 0;
}