#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e14 + 1;
int a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(a, a + n); sort(b, b + m);
    long long ans = inf;
    int ptr = 0;
    long long sa = 0, sb = accumulate(b, b + m, 0ll);
    for (int i = 0; i < n; ++i) {
        while (ptr < m && b[ptr] <= a[i]) sb -= b[ptr], ++ptr;
        long long ta = a[i] * 1ll * i - sa;
        long long tb = sb - a[i] * 1ll * (m - ptr);
        // cout << "a[i] = " << a[i] << " ta = " << ta << " tb = " << tb << endl;
        ans = min(ans, ta + tb);
        sa += a[i];
    }
    sa = accumulate(a, a + n, 0ll); sb = 0;
    ptr = n - 1;
    for (int i = m - 1; i >= 0; --i) {
        while (ptr >= 0 && a[ptr] >= b[i]) sa -= a[ptr], --ptr;
        long long ta = b[i] * 1ll * (ptr + 1) - sa;
        long long tb = sb - b[i] * 1ll * (m - i - 1);
        // cout << "b[i] = " << b[i] << " ta = " << ta << " tb = " << tb << endl;
        ans = min(ans, ta + tb);
        sb += b[i];
    }
    cout << ans << endl;
    return 0;
}