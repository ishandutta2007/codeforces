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
 
bool eval(int x, int y, vector<int> &p, int k) {
    int n = p.size();
    int num = p[y] - (x > 0 ? p[x - 1] : 0);
    if (num >= n - num + k) {
        return true;
    }
    return false;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
            ++p[a[i]];
        }
        for (int i = 1; i < n; i++) {
            p[i] += p[i - 1];
        }
        array<int, 2> ans = {0, 1000000};
        for (int x = 0; x < n; x++) {
            int lo = x, hi = n - 1;
            int y = hi;
            if (!eval(x, y, p, k)) continue;
            for (int j = 0; j < 18; j++) {
                y = (lo + hi) / 2;
                if (eval(x, y, p, k)) {
                    hi = y;
                } else {
                    lo = y + 1;
                }
            }
            y = lo;
            if (y - x < ans[1] - ans[0]) {
                ans = {x, y};
            }
        }
        cout << ans[0] + 1 << " " << ans[1] + 1 << "\n";
        int num = 0;
        int curr = 0;
        int lst = 0;
        for (int i = 0; i < n; i++) {
            if (num == k - 1) {
                cout << i + 1 << " " << n << "\n";
                break;
            } else {
                if (a[i] >= ans[0] && a[i] <= ans[1]) {
                    ++curr;
                } else {
                    --curr;
                }
                if (curr > 0) {
                    cout << lst + 1 << " " << i + 1 << "\n";
                    ++num;
                    curr = 0;
                    lst = i + 1;
                }
            }
        }
    }
}