#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
char s[maxn];

int main() {
    int n, a, b; scanf("%d %d %d", &n, &a, &b);
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == '*') {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && s[j] == '.') ++j;
        int z = j - i;
        if (a > b) {
            ans += min(a, (z + 1) / 2), ans += min(b, z / 2);
            a -= min(a, (z + 1) / 2);
            b -= min(b, z / 2);
        } else {
            ans += min(b, (z + 1) / 2), ans += min(a, z / 2);
            b -= min(b, (z + 1) / 2);
            a -= min(a, z / 2);
        }
        i = j;
    }
    printf("%d\n", ans);
 }