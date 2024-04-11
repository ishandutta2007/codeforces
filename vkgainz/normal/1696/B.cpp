#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <array>
 
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                int j = i;
                ++ans;
                while (j < n && a[j] > 0) {
                    ++j;
                }
                i = j - 1;
            }
        }
        ans = min(ans, 2);
        cout << ans << "\n";
    }
}