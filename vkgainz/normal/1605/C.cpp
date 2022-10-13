#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            array<int, 3> in = {0, 0, 0};
            for (int j = i; j < min(n, i + 20); j++) {
                ++in[s[j] - 'a'];
                if (j > i && in[0] > max(in[1], in[2])) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        if (ans == n + 1) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}