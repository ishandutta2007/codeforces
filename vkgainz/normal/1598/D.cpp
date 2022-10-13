#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        vector<int> fa(n), fb(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            --a[i], --b[i];
            ++fa[a[i]], ++fb[b[i]];
        }
        long long ans = n * 1LL * (n - 1)
            * 1LL * (n - 2) / 6;
        for (int i = 0; i < n; i++) {
            ans -= (fb[b[i]] - 1) * 1LL * (fa[a[i]] - 1);
        }
        cout << ans << "\n";
    }
}