#include <bits/stdc++.h>
using namespace std;

long long solve(long long a, long long s) {
    if (a == 0) return s;

    if (s % 10 >= a % 10) {
        long long b = solve(a / 10, s / 10);
        return b == -1 ? -1 : 10 * b + s % 10 - a % 10;
    } else {
        if (s / 10 % 10 != 1) return -1;
        long long b = solve(a / 10, s / 100);
        return b == -1 ? -1 : 10 * b + 10 + s % 10 - a % 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, s;
        cin >> a >> s;

        cout << solve(a, s) << "\n";
    }
}