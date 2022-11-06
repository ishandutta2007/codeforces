#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    if (n <= 2) return cout << "1\n1\n", 0;
    if (n == 3) return cout << "2\n1 3\n", 0;
    if (n == 4) return cout << "4\n2 4 1 3\n", 0;
    if (n % 2 == 1) {
        cout << n << '\n';
        cout << (n - 1) / 2 + 1 << ' ';
        int ind = (n - 1) / 2 + 2;
        for (int i = 1; i <= (n - 1) / 2; ++i) {
            cout << i << ' ' << ind++ << ' ';
        }
        cout << '\n';
    } else {
        int ind = n / 2 + 1;
        cout << n << '\n';
        for (int i = 1; i <= n / 2; ++i) cout << i << ' ' << ind++ << ' ';
        cout << '\n';
    }
    return 0;
}