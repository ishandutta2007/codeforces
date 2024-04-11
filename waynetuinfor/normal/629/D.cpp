#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const double pi = acos(-1);
double v[maxn], dp[maxn];

struct BIT {
    double _bit[maxn];
    void init() {
        memset(_bit, 0, sizeof(_bit));
    }
#define lowbit(x) (x & -x)
    void add(int x, double v) {
        for (int i = x; i < maxn; i += lowbit(i)) _bit[i] = max(_bit[i], v);
    }
    double qry(int x) {
        double ret = 0.0;
        for (int i = x; i; i -= lowbit(i)) ret = max(ret, _bit[i]);
        return ret;
    }
#undef lowbit
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<double, int>> vec;
    for (int i = 1; i <= n; ++i) {
        double r, h; cin >> r >> h;
        v[i] = r * r * pi * h;
        vec.push_back(make_pair(v[i], i));
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && vec[j].first == vec[i].first) ++j;
        for (int k = i; k < j; ++k) {
            dp[vec[k].second] = bit.qry(vec[k].second - 1) + v[vec[k].second];
        }
        for (int k = i; k < j; ++k) {
            bit.add(vec[k].second, dp[vec[k].second]);
        }
        i = j;
    }
    double ans = 0.0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}