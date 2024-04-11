#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<int> x, y;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            int d = -3;
            for (int j = -1; j <= 1; ++j) {
                if (j == 0) continue;
                if (i + j < 0 || i + j >= n) continue;
                if (a[i + j] != b[i + j] && a[i + j] != a[i]) {
                    if (abs(j) < abs(d)) d = j;
                }
            } 
            if (d == -3) {
                ++ans;
                a[i] = b[i];
            } else {
                ans += d;
                swap(a[i], a[i + d]);
            }
        }
    }
    cout << ans << endl;
}