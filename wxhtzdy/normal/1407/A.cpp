#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b;
        for (int i = 0; i < n; i += 4) {
            if (i + 4 <= n) {
                int sum = a[i] + a[i + 1] + a[i + 2] + a[i + 3];
                if (sum >= 2) {
                    b.push_back(1);
                    b.push_back(1);
                } else {
                    b.push_back(0);
                    b.push_back(0);
                }
            } else {
                int sum = a[i] + a[i + 1];
                if (sum == 2) {
                    b.push_back(1);
                    b.push_back(1);
                } else {
                    b.push_back(0);
                }
            }
        }
        cout << b.size() << '\n';
        for (int i = 0; i < (int) b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}