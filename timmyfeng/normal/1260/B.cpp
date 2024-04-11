#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        cout << ((2 * a - b) % 3 || 2 * a - b < 0 ? "NO" : "YES") << '\n';
    }
}