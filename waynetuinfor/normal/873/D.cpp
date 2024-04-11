#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, k, a[maxn];

void go(int l, int r) {
    if (r - l == 1) return;
    if (k == 0) return;
    k -= 2;
    int m = (l + r) >> 1;
    swap(a[m], a[m - 1]);
    go(m, r); go(l, m);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) a[i] = i + 1;
    if (k % 2 == 0) return cout << "-1" << endl, 0;
    --k;
    go(0, n);
    if (k) return cout << "-1" << endl, 0;
    for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}