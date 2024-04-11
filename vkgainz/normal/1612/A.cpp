#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if ((x + y) % 2) {
            cout << "-1 -1" << "\n";
        } else {
            if (x % 2) {
                cout << x / 2 << " " << (y / 2 + 1) << "\n";
            } else {
                cout << x / 2 << " " << y / 2 << "\n";
            }
        }
    }
}