#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
    int low = 0, high = n;
    while (low < high) {
        int mid = (low + high + 1) / 2;

        long long prod = 1;
        for (int i = 0; i < k && prod <= n; ++i) {
            prod *= mid;
        }

        if (prod <= n) low = mid;
        else high = mid - 1;
    }
    return high;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << solve(n, 2) + solve(n, 3) - solve(n, 6) << "\n";
    }
}