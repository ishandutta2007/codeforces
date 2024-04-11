#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int p = 1;
    vector<int> v;
    while (p <= n) {
        if (p == n) {
            v.push_back(n);
            break;
        }
        if (a[p + 1] < a[p]) {
            v.push_back(p);
            ++p;
            continue;
        }
        int pt = p + 1;
        while (pt <= n && a[pt] >= a[pt - 1]) ++pt;
        v.push_back(pt - 1);
        p = pt;
    }
    if (v.size() == 1) return cout << "0" << endl, 0;
    if (v.size() > 2) return cout << "-1" << endl, 0;
    if (a[n] <= a[1]) cout << n - v[0] << endl;
    else cout << -1 << endl;
    return 0;
}