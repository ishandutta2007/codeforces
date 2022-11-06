#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, l, r; cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a + l - 1, a + r);
    sort(b + l - 1, b + r);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) return cout << "LIE" << endl, 0;
    }
    cout << "TRUTH" << endl;
    return 0;
}