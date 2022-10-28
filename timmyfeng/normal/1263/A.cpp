#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        if (a[2] - a[1] >= a[0]) {
            a[2] -= a[0];
        } else {
            int tmp = a[0];
            tmp -= a[2] - a[1];
            a[2] = a[1];
            a[1] -= (tmp + 1) / 2;
            a[2] -= tmp / 2;
        }
        cout << a[0] + min(a[2], a[1]) << '\n';
    }
}