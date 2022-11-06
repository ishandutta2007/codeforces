#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int a[maxn], l[maxn], r[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int m; cin >> m;
    for (int i = 0; i < m; ++i) cin >> l[i] >> r[i];
    int tot = 0;
    for (int i = 0; i < n; ++i) tot += a[i];
    for (int i = 0; i < m; ++i) {
        if (l[i] <= tot && r[i] >= tot) {
            return cout << tot << endl, 0;
        }
        if (l[i] > tot) return cout << l[i] << endl, 0;
    }
    cout << "-1\n";
    return 0;
}