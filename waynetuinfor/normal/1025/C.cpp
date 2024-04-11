#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
char s[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = n; i < n + n; ++i) s[i] = s[i - n];
    int ans = 0, prv = 0;
    for (int i = 0; i < n + n; ++i) {
        if (i && s[i] == s[i - 1]) prv = 0;
        ++prv;
        ans = max(ans, min(prv, n));
    }
    printf("%d\n", ans);
}