#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y; cin >> y >> x;
    if (x == 0) return cout << "No" << endl, 0;
    int n = x - 1;
    if (n == 0 && y) return cout << "No" << endl, 0;
    if ((y - n) % 2 == 0 && (y - n) >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}