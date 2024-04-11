#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = i, y = j;
            int c = 0;
            int z = 0;
            while (x > 0 || y > 0) {
                z++;
                if (x % k != y % k) {
                    c = z;
                }
                x /= k;
                y /= k;
            }
            ans.emplace_back(c);
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
    for (int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}