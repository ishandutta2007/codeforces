#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> o, e;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2) o.push_back(i);
            else e.push_back(i);
        }
        if (n % 2 == 0) {
            if (o.size() != n / 2) {
                cout << -1 << "\n";
            }
            else {
                long long ans = 0LL;
                long long cmp = 0LL;
                for (int i = 0; i < n / 2; i++) {
                    ans += abs(2 * i - o[i]);
                }
                for (int i = 0; i < n / 2; i++) {
                    cmp += abs(2 * i - e[i]);
                }
                cout << min(ans, cmp) << "\n";
            }
        }
        else {
            if (o.size() != n / 2 && o.size() != (n / 2 + 1)) {
                cout << -1 << "\n";
            }
            else {
                if (o.size() == n / 2)
                    swap(o, e);
                long long ans = 0LL;
                for (int i = 0; i < n / 2 + 1; i++) {
                    ans += abs(2 * i - o[i]);
                }
                cout << ans << "\n";
            }
        }
        
    }
}