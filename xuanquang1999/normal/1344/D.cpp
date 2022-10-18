#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const long long oo = 3e18;

int n;
long long a[MAXN], b[MAXN], ans[MAXN], k;

long long score(long long a, long long b) {
    return a - (b*b + b*(b-1) + (b-1)*(b-1));
}

bool check(long long lim) {
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        long long lo = 0, hi = a[i];
        b[i] = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (score(a[i], mid) >= lim) {
                b[i] = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        sum += b[i];
    }
    return (sum >= k);
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    long long l = -oo, r = oo, res = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            for(int i = 0; i < n; ++i)
                ans[i] = b[i];
            l = mid + 1;
        } else
            r = mid - 1;
    }

    long long sum = accumulate(ans, ans+n, 0LL);
    for(int i = 0; i < n; ++i) {
        if (score(a[i], ans[i]) == res && sum > k) {
            --ans[i];
            --sum;
        }
    }

    for(int i = 0; i < n; ++i)
        cout << ans[i] << ' ';

    return 0;
}