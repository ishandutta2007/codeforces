#include <bits/stdc++.h>

using namespace std;

long long get(long long R) {
    long long s = 1, e = 1e9 + 5;
    while (s < e) {
        long long m = (s + e + 1) / 2;
        if (m * m > R) e = m - 1;
        else s = m;
    }
    long long res = (s - 1) * 3;
    res += min(R / s, s + 2) - s + 1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long L, R;
        cin >> L >> R;
        printf("%lld\n", get(R) - get(L - 1));
    }
    return 0;
}