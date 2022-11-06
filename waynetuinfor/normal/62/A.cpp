#include <bits/stdc++.h>
using namespace std;


bool solve(int x, int y) {
    if (x > y + 1) return false;
    if (y > 2 * (x + 1)) return false;
    return true;
}

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (solve(b, c) || solve(a, d)) cout << "YES" << endl;
    else cout << "NO" << endl;
}