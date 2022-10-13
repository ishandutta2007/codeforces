#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        vector<int> b(7);
        for (int i = 0; i < 7; i++) {
            cin >> b[i];
        }
        int a = b[6] - b[5];
        int x = b[6] - b[4];
        int c = b[6] - a - x;
        cout << a << " " << x << " " << c << "\n";
    }
}