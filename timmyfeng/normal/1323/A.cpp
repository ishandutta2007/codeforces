#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> even;
        vector<int> odd;
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            if (a % 2) {
                odd.push_back(i);
            } else {
                even.push_back(i);
            }
        }
        if (even.size()) {
            cout << 1 << ' ' << even.front() << '\n';
        } else if (odd.size() >= 2) {
            cout << 2 << ' ' << odd[0] << ' ' << odd[1] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}