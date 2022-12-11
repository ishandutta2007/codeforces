#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7, M = 998244353;
int a[N];
int pref[N];
int suff[N];

void init(int n) {
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (i % 2 == 1)
            pref[i] -= a[i];
        else
            pref[i] += a[i];
    }

    suff[n + 1] = 0;
    for (int i = n; i >= 1; i--)
        suff[i] = suff[i + 1] + a[i];
}

int get0(int l, int r) {
    //assert((r - l + 2) % 2 == 1);
    if (l % 2 == 1)
        return pref[r] - pref[l - 1];
    return pref[l - 1] - pref[r];
}

int get_summ(int l, int r) {
    return suff[l] - suff[r + 1];
}

int get(int b, int e, int boost) {
    int summ = boost;
    int ans = 0;
    for (int i = b; i < e; i++) {
        summ += a[i];
        int l = -1, r = N, mid;
        while (r - l > 1) {
            mid = (l + r) / 2;

            int p_start = i + 2 * mid + 1;
            if (p_start > e) {
                r = mid;
                continue;
            }

            if (summ - get_summ(p_start, e) + get0(i + 1, p_start - 1) < 0)
                l = mid;
            else
                r = mid;
        }
        ans += l + 1;
    }
    ans %= M;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    init(n);
    int ans = 0;
    ans += get(1, n, 0);
    ans += get(1, n - 1, a[n]);
    ans += get(2, n, -a[1]);
    ans += get(2, n - 1, a[n] - a[1]);
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        sm += a[i];
        if (sm > suff[i + 1])
            ans++;
    }
    cout << ans % M << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}