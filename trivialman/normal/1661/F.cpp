#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5 + 5;
const LL INF = 1e18;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, a[N];
LL m;

LL split(int n, int m) {
    m++;
    int low = n / m, highnum = n % m;
    return 1ll * low * low * (m - highnum) + 1ll * (low + 1) * (low + 1) * highnum;
}

pair<LL, LL> calc(LL sub) {
    LL sum = 0, nsp = 0;
    rep(i, 1, n) {
        int l = 0, r = a[i] - 1, ans = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            LL diff = split(a[i], mid) - split(a[i], mid + 1);
            if (diff <= sub)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        sum += split(a[i], ans);
        nsp += ans;
    }
    return {sum, nsp};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    cin >> m;
    rrep(i, n, 1) a[i] -= a[i - 1];
    sort(a + 1, a + n + 1);

    LL l = 1, r = 1e18, sub = 0;
    while (l <= r) {
        LL mid = l + r >> 1;
        auto [sum, nsp] = calc(mid);
        if (sum <= m)
            sub = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    //auto [sum1, nsp1] = calc(sub);     // <= m
    auto [sum2, nsp2] = calc(sub + 1); // > m
    cout << nsp2 + (sum2 - m + sub) / (sub + 1);
    return 0;
}