#include <bits/stdc++.h>
using namespace std;

long long calc(long long x) {
    long long res = 0;
    while (x) res += x % 10, x /= 10;
    return res;
}

int main() {
    long long n; cin >> n;
    long long ans = calc(n);
    for (long long i = 9; i <= n; i = i * 10 + 9) ans = max(ans, calc(i) + calc(n - i));
    cout << ans << endl;
}