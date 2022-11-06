#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int x[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    int z = *max_element(x, x + n) - *min_element(x, x + n);
    if (z == 0 || z == 1) {
        cout << n << endl;
        for (int i = 0; i < n; ++i) cout << x[i] << ' '; cout << endl;
        return 0;
    }
    int oto = *max_element(x, x + n), tot = *min_element(x, x + n);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] == oto) ++a;
        else if (x[i] == tot) ++c;
        else ++b;
    }
    vector<int> v;
    int ans = 0;
    for (int i = 0; i < b; ++i) v.push_back(oto - 1), ++ans;
    for (int i = 0; i < min(a, c); ++i) v.push_back(oto - 1), v.push_back(oto - 1);
    for (int i = 0; i < a - min(a, c); ++i) v.push_back(oto), ++ans;
    for (int i = 0; i < c - min(a, c); ++i) v.push_back(tot), ++ans;
    int ans1 = 0;
    vector<int> vv;
    for (int i = 0; i < b / 2; ++i) vv.push_back(oto), vv.push_back(tot);
    if (b % 2 == 1) vv.push_back(oto - 1), ++ans1;
    for (int i = 0; i < a; ++i) vv.push_back(oto), ++ans1;
    for (int i = 0; i < c; ++i) vv.push_back(tot), ++ans1;
    if (ans1 < ans) {
        cout << ans1 << endl;
        for (int i : vv) cout << i << ' '; cout << endl;
    } else {
        cout << ans << endl;
        for (int i : v) cout << i << ' '; cout << endl;
    }
    return 0;
}