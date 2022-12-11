#include <bits/stdc++.h>
#define int long long

using namespace std;

vector <pair <int, int>> res;

void rec(int l, int r) {
    if (l == r) return;
    int len = r - l + 1;
    int m = (l + r) / 2;
    if (len % 2 == 0) {
        rec(l, m);
        rec(m + 1, r);
        for (int i = 0; i < len / 2; i++) {
            res.emplace_back(l + i, m + 1 + i);
        }
        return;
    }
    rec(l, r - 1);
}

signed main() {
    int n;
    cin >> n;
    int len = 1;
    while (len * 2 <= n) len *= 2;
    rec(1, len);
    rec(n - len + 1, n);
    cout << res.size() << endl;
    for (auto elem : res) {
        cout << elem.first << ' ' << elem.second << "\n";
    }
}