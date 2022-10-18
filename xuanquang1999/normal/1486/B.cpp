#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, x[MAXN], y[MAXN];

long long calc(int x[]) {
    if (n%2 == 1) return 1;
    return x[n/2] - x[n/2-1] + 1;
}

void solve() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    sort(x, x+n);
    sort(y, y+n);

    long long ans = calc(x) * calc(y);
    printf("%lld\n", ans);
}

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) solve();

    return 0;
}