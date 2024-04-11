#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], v[maxn];
long long s[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    long long r = *max_element(s, s + n);
    for (int i = 0; i < n; ++i) {
        long long ans = s[i] + n - r;
        if (ans < 1 || ans > n) {
            puts("-1");
            return 0;
        }
        if (v[ans]) {
            puts("-1");
            return 0;
        }
        v[ans] = 1;
    }
    for (int i = 0; i < n; ++i) printf("%lld ", s[i] + n - r);
    puts("");
    return 0;
}