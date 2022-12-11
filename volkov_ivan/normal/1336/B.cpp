#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;

int get(int a, int b, int c) {
    return (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c);
}

int check(vector <int> &a, vector <int> &b, vector <int> &c) {
    int res = get(a[0], b[0], c[0]);
    for (int elem : a) {
        int pos = --upper_bound(b.begin(), b.end(), elem) - b.begin();
        if (pos < 0) continue;
        int pos2 = lower_bound(c.begin(), c.end(), elem) - c.begin();
        if (pos2 >= (int) c.size()) continue;
        res = min(res, get(elem, b[pos], c[pos2]));
    }
    return res;
}

void solve() {
    int na, nb, nc;
    cin >> na >> nb >> nc;
    vector <int> a(na), b(nb), c(nc);
    for (int i = 0; i < na; i++) cin >> a[i];
    for (int i = 0; i < nb; i++) cin >> b[i];
    for (int i = 0; i < nc; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int res = check(a, b, c);
    res = min(res, check(a, c, b));
    res = min(res, check(b, a, c));
    res = min(res, check(b, c, a));
    res = min(res, check(c, a, b));
    res = min(res, check(c, b, a));
    cout << res << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}