#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        if (n == 1 && m == 1) {
            cout << 0 << "\n";
        } else {
            cout << min(2, min(n, m)) << "\n";
        }    
    }
}