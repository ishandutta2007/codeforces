#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(1, min(a, 1 + b + c - a)) << ' ';
        cout << min(a, b + c - 1) << '\n';
    }
}