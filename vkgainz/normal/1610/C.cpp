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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        int lo = 0, hi = n;
        for (int j = 0; j < 20; j++) {
            int mid = (lo + hi + 1) / 2;
            pair<int, int> look = {0, mid - 1};
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (look.first <= b[i] 
                        && a[i] >= look.second) {
                    ++ans;
                    ++look.first;
                    --look.second;
                }
            }
            if (ans >= mid) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << "\n";
    }
}