#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int num(vector<int> &a, double x, double y) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        double look = x * (1 - i)
            + y * i;
        if (abs(look - a[i]) > 1e-3) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 0 << "\n";
        } else {
            int ans = n;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    double sub = (a[i] - a[j]) * 1.0 / (i - j);
                    double a2 = (a[i] + sub * (1 - i));
                    double a1 = a2 - sub;
                    ans = min(ans, num(a, a1, a2));
                }
            }
            cout << ans << "\n";
        }
    }
}