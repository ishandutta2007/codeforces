#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;
        if (n > m) {
            swap(n, m);
        }
        int tmp = __gcd(n, m);
        n /= tmp;
        m /= tmp;
        cout << ((k - 1) * n + 1 >= m ? "OBEY" : "REBEL") << '\n';
    }
}