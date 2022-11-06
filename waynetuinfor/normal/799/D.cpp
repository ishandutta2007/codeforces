#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int m[maxn], a, b, h, w, n;

int get(int a, int b) { return a % b == 0 ? a / b : a / b + 1; }

void mul(long long &a, int b) {
    a *= b;
    if (a >= maxn) a = maxn - 1;
}

bool check(int used) {
    int hf = used / 2;
    vector<long long> dp(maxn, 0);
    for (int s = 0; s < (1 << hf); ++s) {
        long long nh = 1, nw = 1;
        for (int i = 0; i < hf; ++i) {
            if ((1 << i) & s) mul(nh, m[i]);
            else mul(nw, m[i]);
        }
        nh = min(nh, 1ll * maxn - 1);
        dp[nh] = max(dp[nh], nw);
    }
    for (int i = maxn - 2; i >= 0; --i) dp[i] = max(dp[i], dp[i + 1]);
    for (int s = 0; s < (1 << (used - hf)); ++s) {
        long long nh = 1, nw = 1;
        for (int i = 0; i < used - hf; ++i) {
            if ((1 << i) & s) mul(nh, m[i + hf]);
            else mul(nw, m[i + hf]);
        }
        if (nw * dp[get(get(a, h), nh)] >= get(b, w)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b >> h >> w >> n;
    for (int i = 0; i < n; ++i) cin >> m[i];
    sort(m, m + n); reverse(m, m + n);
    if (h >= a && w >= b || h >= b && w >= a) return cout << "0" << endl, 0;
    int ans = maxn;
    for (int i = 1; i <= n; ++i) if (check(i)) {
        ans = i; break;
    }
    swap(a, b);
    for (int i = 1; i <= n; ++i) if (check(i)) {
        ans = min(ans, i);
        break;
    }
    if (ans == maxn) ans = -1;
    cout << ans << endl;
    return 0;
}