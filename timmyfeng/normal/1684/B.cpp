#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long long a, b, c; cin >> a >> b >> c;

        cout << a + b + c << " " << b + c << " " << c << "\n";
    }
}