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
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        int lo = 0, hi = 1e9;
        for (int j = 0; j < 35; j++) {
            vector<int> tmp;
            tmp.insert(tmp.end(), h.begin(), h.end());
            int mid = (lo + hi + 1) / 2;
            bool work = true;
            for (int i = n - 1; i >= 2; i--) {
                if (tmp[i] > mid) {
                    int take = min(h[i] / 3, (tmp[i] - mid) / 3);
                    tmp[i] -= 3 * take;
                    tmp[i - 1] += take;
                    tmp[i - 2] += 2 * take;
                }
            }
            work = *min_element(tmp.begin(), tmp.end()) >= mid;
            if (work) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << "\n";
    }
}