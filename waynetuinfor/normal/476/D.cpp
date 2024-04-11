#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    cout << k * (6 * (n - 1) + 5) << endl;
    for (int i = 0; i < n; ++i) {
        cout << k * (6 * i + 1) << ' ' << k * (6 * i + 2) << ' ' << k * (6 * i + 3) << ' ' << k * (6 * i + 5) << endl;
    }    
    return 0;
}