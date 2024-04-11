#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        long long sol = n * (n + 1) / 2;
        long long xtra = (n - m) % (m + 1);
        long long sz = (n - m) / (m + 1);
        sol -= (m + 1 - xtra) * sz * (sz + 1) / 2;
        sol -= xtra * (sz + 1) * (sz + 2) / 2;
        cout << sol << '\n';
    }
}