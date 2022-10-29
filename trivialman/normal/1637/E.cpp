#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e9;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int T, n, m, k, x, y;
int a[N], nums[N];
vector<int> cnt[N];
set<ar2> bad;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, m) cin >> x >> y, bad.insert({min(x, y), max(x, y)});
        sort(a + 1, a + n + 1);
        k = 0;
        rep(i, 1, n) {
            int j = i;
            for (; j <= n && a[j] == a[i]; j++)
                ;
            cnt[j - i].PB(a[i]), nums[++k] = j - i, i = j - 1;
        }
        sort(nums + 1, nums + k + 1);
        k = unique(nums + 1, nums + k + 1) - nums - 1;

        LL ans = 0;
        rep(i, 1, k) {
            int c = nums[i];
            sort(cnt[c].begin(), cnt[c].end(), [](int x, int y) { return x > y; });
            for (auto x : cnt[c]) {
                rep(j, 1, i) {
                    int c1 = nums[j];
                    for (auto y : cnt[c1])
                        if (x != y && !bad.count({min(x, y), max(x, y)})) {
                            ans = max(ans, 1ll * (c + c1) * (x + y));
                            break;
                        }
                }
            }
        }

        bad.clear();
        rep(i, 1, k) cnt[nums[i]].clear();
        cout << ans << endl;
    }
    return 0;
}