#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 998244353;
char s[maxn];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    int i = 0, j = n - 1;
    while (i < n && s[i] == s[0]) ++i;
    while (j >= 0 && s[j] == s[n - 1]) --j;
    int a = i, b = n - 1 - j;
    if (s[0] != s[n - 1]) printf("%d\n", (a + 1 + b) % mod);
    else printf("%d\n", (a + 1) * 1ll * (b + 1) % mod);
}