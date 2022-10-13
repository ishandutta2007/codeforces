#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

bool p[1000001];

int main() {
    int t; cin >> t;
    while (t--) {
        int n; 
        long long h; cin >> n >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long lo = 1LL, hi = h;
        for (int j = 0; j < 70; j++) {
            long long mid = (lo + hi) / 2;
            long long lst = a[0];
            long long num = mid;
            for (int i = 0; i < n; i++) {
                if (lst + mid - 1 < a[i]) {
                    num += mid;
                } else {
                    num += a[i] - lst;
                }
                lst = a[i];
            }
            if (num >= h) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << "\n";
    }
}