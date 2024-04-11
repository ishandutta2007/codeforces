#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e9 + 1;
const int N = 1e5 + 5, M = 6.1e7 + 5;
mt19937 rng(time(0));

int T, n, x, y;
int a[N], cnt[M];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    rep(i, 1, n) cin >> a[i];

    int k = 300, base = 3e7, ans = 1;
    rep(d, 0, k) {
        rep(i, 1, n) ans = max(ans, ++cnt[a[i] - d * i + base]);
        rep(i, 1, n)-- cnt[a[i] - d * i + base];
        rep(i, 1, n) ans = max(ans, ++cnt[a[i] + d * i + base]);
        rep(i, 1, n)-- cnt[a[i] + d * i + base];
    }
    int q = 100000 / k + 10;
    rep(i, 2, n) {
        rep(j, max(i - q, 1), i - 1) if ((a[i] - a[j]) % (i - j) == 0) {
            int id = base + (a[i] - a[j]) / (i - j);
            ++cnt[id], ans = max(ans, cnt[id] + 1);
        }
        rep(j, max(i - q, 1), i - 1) if ((a[i] - a[j]) % (i - j) == 0)-- cnt[base + (a[i] - a[j]) / (i - j)];
    }
    cout << n - ans;
    return 0;
}