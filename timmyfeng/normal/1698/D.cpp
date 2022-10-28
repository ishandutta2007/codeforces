#include <bits/stdc++.h>
using namespace std;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int result = 0;
    for (int i = 0; i < r - l + 1; ++i) {
        int a; cin >> a;
        result += (l <= a && a <= r);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        int low = 1, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (query(low, mid) % 2) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << "! " << low << endl;
    }
}