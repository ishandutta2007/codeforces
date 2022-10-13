#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        int use = -1;
        long long num = 1LL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            while (a[i] % 2 == 0) {
                a[i] /= 2;
                num *= 2;
            }
            if (use == -1 || a[i] > a[use]) {
                use = i;
            }
        }
        a[use] *= num;
        cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
    }
}