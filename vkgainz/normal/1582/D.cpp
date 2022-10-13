#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <array>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n % 2 == 0) {
            for (int i = 0; i < n; i += 2) {
                cout << a[i + 1] << " " << -a[i] << " ";
            }
            cout << "\n";
        } else {
            for (int i = 0; i < n - 3; i += 2) {
                cout << a[i + 1] << " " << -a[i] << " ";
            }
            if (a[n - 3] + a[n - 2] != 0) {
                cout << a[n - 1] << " " << a[n - 1] << " " << -(a[n - 3] + a[n - 2]) << "\n";
            } else {
                cout << a[n - 1] << " " << 2 * a[n - 1] << " " << a[n - 3] << "\n";
            }
        }
    }
}