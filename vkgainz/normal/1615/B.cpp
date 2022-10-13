#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <math.h>
#include <array>
 
using namespace std;
 
int pref[200001][21];

int main() {
    int t; cin >> t;
    for (int i = 1; i <= 200000; i++) {
        for (int j = 0; j < 20; j++) {
            if (i & (1 << j)) {
                pref[i][j] = pref[i - 1][j] + 1;
            } else {
                pref[i][j] = pref[i - 1][j];
            }
        }
    }
    while (t--) {
        int l, r; cin >> l >> r;
        int ans = 1e9;
        for (int b = 0; b < 20; b++) {
            ans = min(ans, (r - l + 1) - (pref[r][b] - pref[l - 1][b]));
        }
        cout << ans << "\n";
    }
}