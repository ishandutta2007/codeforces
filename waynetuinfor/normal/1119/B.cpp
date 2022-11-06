#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn];

int main() {
    int n, h; scanf("%d%d", &n, &h);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> b(a, a + i);
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        long long x = 0;
        for (int j = 0; j < i; j += 2) {
            x += b[j];
        }
        if (x <= h)
            ans = i;
    }
    printf("%d\n", ans);
}