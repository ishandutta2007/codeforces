#include <bits/stdc++.h>
using namespace std;

bool sqr(int n) {
    int low = 0, high = 1 << 15;
    while (low < high) {
        int mid = (low + high) / 2;
        if (mid * mid < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low * low == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << ((n % 2 == 0 && sqr(n / 2)) || (n % 4 == 0 && sqr(n / 4)) ? "YES" : "NO") << "\n";
    }
}