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
        string a, b; cin >> a >> b;
        int off = 0, noff = 0;
        array<int, 2> zer = {0, 0}, one = {0, 0};
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                ++off;
                zer[0] += a[i] == '0';
                one[0] += a[i] == '1';
            } else {
                ++noff;
                zer[1] += a[i] == '0';
                one[1] += a[i] == '1';
            }
        }
        int ans = 1e6;
        if (off % 2 == 0 && one[0] == zer[0]) {
            ans = min(ans, off);
        } 
        if (noff % 2 == 1 && one[1] - zer[1] == 1) {
            ans = min(ans, noff);
        }
        if (ans == 1e6) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
}