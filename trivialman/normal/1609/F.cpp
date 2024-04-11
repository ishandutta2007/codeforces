#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 1e6 + 5;
const LL INF = (1ll << 62) - 1;

int n;
int cnt[64];
LL a[N], ans = 0;

inline int nbit(LL x) { return __builtin_popcountll(x); }

void solve(int l, int r) {
    if (l == r) {
        ans++;
        return;
    }
    int m = l + r >> 1;
    solve(l, m), solve(m + 1, r);

    memset(cnt, 0, sizeof cnt);
    LL ma = 0, mi = INF, mi1 = INF, mi2 = a[m + 1];
    int r_max = m, r_min = m + 1;
    rrep(i, m, l) {
        ma = max(ma, a[i]), mi = min(mi, a[i]);
        if (r_max < r && a[r_max + 1] <= ma) {
            while (r_max < r && a[r_max + 1] <= ma)
                r_max++, mi1 = min(mi1, a[r_max]), cnt[nbit(mi1)]++;
        }
        if (r_min <= r_max && a[r_min] >= mi) {
            while (r_min <= r_max && a[r_min] >= mi)
                cnt[nbit(mi2)]--, r_min++, mi2 = min(mi2, a[r_min]);
        }
        if (r_max > m)
            ans += (nbit(ma) == nbit(mi)) * (r_min - m - 1) + cnt[nbit(ma)];
    }

    memset(cnt, 0, sizeof cnt);
    ma = 0, mi = INF, mi1 = INF, mi2 = a[m];
    int l_max = m + 1, l_min = m;
    rep(i, m + 1, r) {
        ma = max(ma, a[i]), mi = min(mi, a[i]);
        if (l_max > l && a[l_max - 1] < ma) {
            while (l_max > l && a[l_max - 1] < ma)
                l_max--, mi1 = min(mi1, a[l_max]), cnt[nbit(mi1)]++;
        }
        if (l_min >= l_max && a[l_min] >= mi) {
            while (l_min >= l_max && a[l_min] >= mi)
                cnt[nbit(mi2)]--, l_min--, mi2 = min(mi2, a[l_min]);
        }
        if (l_max <= m)
            ans += (nbit(ma) == nbit(mi)) * (m - l_min) + cnt[nbit(ma)];
    }
}

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%lld", a + i);
    solve(1, n);
    cout << ans << endl;
    return 0;
}