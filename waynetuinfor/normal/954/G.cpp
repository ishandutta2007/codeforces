#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
const long long inf = 4000000000000000000ll;
long long a[maxn], k, s[maxn];
int n, r;

bool check(long long t) {
    long long u = k;
    vector<long long> ts(s, s + maxn);
    long long now = 0;
    for (int i = 1; i <= n; ++i) {
        now += ts[i];
        if (now >= t) continue;
        long long nd = t - now;
        if (u < nd) return false;
        u -= nd;
        ts[i + 1] += nd; ts[min(n + 1, i + r + r + 1)] -= nd;
    }
    return true;
}

int main() {
    cin >> n >> r >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        s[max(1, i - r)] += a[i];
        s[min(n + 1, i + r + 1)] -= a[i];
    }
    int d = 62;
    long long ans = 0;
    while (d--) if ((1ll << d) + ans < inf) {
        if (check(ans + (1ll << d))) ans += (1ll << d);
    }
    cout << ans << endl;
    return 0;
}