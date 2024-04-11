#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> d(n);
        bool work = true;
        for (int i = 0; i < n; i++) {
            int x = 2 * b[(i + n - 1) % n]
                - b[(i - 2 + n) % n]
                - b[i];
            if (abs(x) % n) {
                cout << "NO" << "\n";
                work = false;
                break;
            } else {
                d[i] = x / n;
            }
        }
        if (!work) continue;
        vector<int> a(n);
        a[0] = 0;
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + d[i];
        }
        long long s = 0LL;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                s += a[0];
            } else {
                s += (n - i + 1) * 1LL * a[i];
            }
        }
        long long add = (b[0] - s) / (n * 1LL * (n + 1) / 2);
        if (abs(b[0] - s) % (n * 1LL * (n + 1) / 2)) {
            cout << "NO" << "\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            a[i] += add;
        }
        if (*min_element(a.begin(), a.end()) <= 0) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
}