#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int numone = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) ++numone;
        }
        sort(a.begin(), a.end());
        if (numone == n || numone == 0) {
            cout << "YES" << "\n";
            continue;
        } else {
            bool work = true;
            for (int i = 0; i < n - 1; i++) {
                if (a[i + 1] == a[i] + 1) {
                    cout << "NO" << "\n";
                    work = false;
                    break;
                }
            }
            if (work) cout << "YES" << "\n";
        }
    }
}