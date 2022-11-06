#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
long long d[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; long long A, s = 0; cin >> n >> A;
    for (int i = 1; i <= n; ++i) cin >> d[i], s += d[i];
    for (int i = 1; i <= n; ++i) {
        long long lb = n - 1, ub = s - d[i];
        long long x = min(A - lb, d[i]), y = max(A - ub, 1LL);
        cout << d[i] - (x - y + 1) << ' ';
    }
    return 0;
}