#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    if (n == k) return cout << "0 0" << endl, 0;
    if (k == 0) return cout << "0 0" << endl, 0;
    int ans = 2 * k;
    cout << 1 << ' ' << min(n - k, ans) << endl;
    return 0;
}