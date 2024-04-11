#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        bool ok = 0;
        for (int i = 0; i < n - 2; i++) {
            if (a[i].first + a[i + 1].first <= a[n - 1].first) {
                cout << a[i].second + 1 << " " << a[i + 1].second + 1 << " " << a[n - 1].second + 1 << endl;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
        }
    }
    return 0;
}