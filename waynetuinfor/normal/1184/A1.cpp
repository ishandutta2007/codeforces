#include <bits/stdc++.h>
using namespace std;

int main() {
    long long r; cin >> r;
    for (long long x = 1; x + x * x + 1 < r; ++x) {
        if ((r - 1 - x - x * x) % (2 * x) == 0) {
            cout << x << ' ' << (r - 1 - x - x * x) / (2 * x) << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}