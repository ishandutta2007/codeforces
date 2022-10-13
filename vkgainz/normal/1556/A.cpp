#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int c, d; cin >> c >> d;
        if ((c + d) % 2) {
            cout << -1 << "\n";
        }
        else {
            if (c == 0 && d == 0) cout << 0 << "\n";
            else if (c == d) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
    }
}