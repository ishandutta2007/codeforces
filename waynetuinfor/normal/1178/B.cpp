#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], b[maxn];
char s[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);

    for (int i = 1; i < n; ++i) {
        if (s[i] == 'v' && s[i - 1] == 'v') a[i] = 1;
        a[i] += a[i - 1];
    }

    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == 'v' && s[i + 1] == 'v') b[i] = 1;
        b[i] += b[i + 1];
    }

    long long ans = 0;
    for (int i = 1; i < n - 1; ++i) 
        if (s[i] == 'o') ans += a[i - 1] * 1ll * b[i + 1];
    printf("%lld\n", ans);
    return 0;
}