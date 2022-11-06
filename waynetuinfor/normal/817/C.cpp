#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1000000000000000001;
bool check(long long, long long);

int main() {
    long long n, s; cin >> n >> s;
    long long d = 1LL, ans = maxn;
    // cout << "ans = " << ans << endl;
    while (d <= maxn) d <<= 1;
    while (d >>= 1) if (ans - d >= 1) if (check(ans - d, s)) ans -= d;
    // cout << "ans = " << ans << endl;
    cout << (n >= ans ? n - ans + 1LL : 0) << endl;
    return 0;
}

bool check(long long num, long long s) {
    // cout << "check: " << num << endl;
    long long dig = 0;
    long long tmp = num;
    while (tmp) {
        dig += tmp % 10;
        tmp /= 10;
    }
    // cout << "num = " << num << " dig = " << dig << "ret = " << (num - dig >= s) << endl;
    return num - dig >= s;
}