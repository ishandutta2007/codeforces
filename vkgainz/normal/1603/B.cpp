#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if (y >= x) {
            int b = (y % x) / 2;
            int a = y / x;
            cout << x * a + b << "\n";
        } else {
            cout << x + y << "\n";
        }
    }
}