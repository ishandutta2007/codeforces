#include <bits/stdc++.h>
#define double long double
using namespace std;

const int maxn = 1e5 + 10, inf = 2e9 + 1;
const double eps = 1e-10;
int v[maxn], m[maxn], n, k, h, ans[maxn];
vector<int> ord;

bool check(double t) {
    size_t ptr = 0;
    vector<int> tans(maxn);
    for (int i = 1; i <= k; ++i) {
        double req = i * h * 1.0;
        while (ptr < n && v[ord[ptr]] * t < req) ++ptr;
        if (ptr >= n) return false;
        tans[i] = ord[ptr];
        ++ptr;
    }
    for (int i = 1; i <= k; ++i) ans[i] = tans[i];
    return true;
}

double bs(double l, double r, int dep) {
    if (dep > 120) return l;
    double m = (l + r) / 2.0;
    if (check(m)) return bs(l, m, dep + 1);
    return bs(m, r, dep + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> h;
    for (int i = 0; i < n; ++i) cin >> m[i];
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](const int &a, const int &b) { return m[a] == m[b] ? v[a] < v[b] : m[a] < m[b]; });
    bs(0, inf, 0);
    for (int i = 1; i <= k; ++i) cout << ans[i] + 1 << ' '; cout << endl;
    return 0;
}