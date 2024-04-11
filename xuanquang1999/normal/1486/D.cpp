#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, k, a[MAXN];

bool check(int x) {
    vector<int> d(n+1);
    for(int i = 1; i <= n; ++i) {
        int val = (a[i] >= x) ? 1 : -1;
        d[i] = d[i-1] + val;
    }

    int minD = 0;
    for(int i = k; i <= n; ++i) {
        minD = min(minD, d[i-k]);
        if (d[i] - minD > 0) return true;
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int lo = 1, hi = n, res = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else
            hi = mid - 1;
    }

    printf("%d\n", res);

    return 0;
}