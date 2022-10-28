#include <bits/stdc++.h>
using namespace std;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, k;
    cin >> n >> t >> k;

    int low = 1, high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (mid - query(1, mid) < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << "! " << low << endl;
}