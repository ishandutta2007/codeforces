#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long a, m;
        cin >> a >> m;
        m /= __gcd(a, m);
        long long sol = m;
        for (long long i = 2; i * i <= m; i++) {
            int ct = 0;
            while (m % i == 0) {
                ct++;
                m /= i;
            }
            if (ct) {
                sol -= sol / i;
            }
        }
        if (m > 1) {
            sol -= sol / m;
        }
        cout << sol << '\n';
    }
}