#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        int na = (a + b) / 2, nb = (a + b + 1) / 2;
        set<int> pos;
        for (int x1 = 0; x1 <= a; x1++) {
            int x2 = a - x1;
            //bob first
            int y1 = na - x1, y2 = b - y1;
            if (y1 < 0 || y2 < 0 || (x2 + y2) != nb) {
            }
            else {
                pos.insert(x2 + y1);
            }
            y1 = nb - x1, y2 = b - y1;
            if (y1 < 0 || y2 < 0 || (x2 + y2) != na) {
            }
            else {
                pos.insert(x2 + y1);
            }
        }
        cout << pos.size() << "\n";
        for (int x : pos)
            cout << x << " ";
        cout << "\n";
    }
}