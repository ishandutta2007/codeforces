#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 5005;
mt19937 rng(time(0));

int T, n, a[N], fa[N];

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) fa[i] = a[i] == 1 ? i + 1 : i;
        fa[n + 1] = n + 1;

        LL ans = 0;
        rep(i, 1, n) if (a[i] > 1) {
            if (a[i] > n)
                ans += 1ll * (a[i] - n), a[i] = n;
            while (a[i] > 1) {
                int j = i;
                while (j <= n) {
                    int tmp = a[j];
                    a[j] = max(a[j] - 1, 1);
                    if (j <= n && a[j] == 1)
                        fa[j] = j + 1;
                    j = j + tmp <= n ? find(j + tmp) : j + tmp;
                }
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}