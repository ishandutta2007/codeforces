#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int k = 30; k >= 1; --k) {
        long long v = ((1ll << k) - 1) * (1 << (k - 1));
        if (v <= n && n % v == 0) return cout << v << endl, 0;
    }
    return 0;
}