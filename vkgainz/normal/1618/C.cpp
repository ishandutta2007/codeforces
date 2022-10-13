#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

bool work(long long d, vector<long long> &a, int n) {
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (a[i] % d) {
            c[i] = 1;
        } else {
            c[i] = 0;
        }
        if (i && c[i] == c[i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long d = 0LL;
        for (int i = 0; i < n; i += 2) {
            d = __gcd(d, a[i]);
        }
        if (work(d, a, n)) {
            cout << d << "\n";
        } else {
            d = 0;
            for (int i = 1; i < n; i += 2) {
                d = __gcd(d, a[i]);
            }
            if (work(d, a, n)) {
                cout << d << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
}