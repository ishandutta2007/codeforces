#include <bits/stdc++.h>
using namespace std;

bool check(long long);
long long n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    if (n <= m) return cout << n << '\n', 0;
    long long d = 1LL, ans = 2000000000LL;
    while (d <= 2000000000LL) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans + m << '\n';
    return 0;
}

bool check(long long x) {
    return x * (1LL + x) / 2 >= n - m;
}