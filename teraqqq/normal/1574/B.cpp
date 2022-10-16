#include <bits/stdc++.h>

using namespace std;

bool check() {
    int a, b, c, m; cin >> a >> b >> c >> m;

    m = a + b + c - m; // - 
    if ((a?1:0) + (b?1:0) + (c?1:0) > m) return false;
    if (b + c < m / 2) return false;
    if (a + c < m / 2) return false;
    if (a + b < m / 2) return false;
    if (a + b + c < m) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        bool res = check();
        cout << (res ? "YES" : "NO") << '\n';
    }
}