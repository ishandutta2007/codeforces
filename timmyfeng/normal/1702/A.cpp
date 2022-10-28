#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int m; cin >> m;

        int power = 1;
        while (10LL * power <= m) power *= 10;

        cout << m - power << "\n";
    }
}