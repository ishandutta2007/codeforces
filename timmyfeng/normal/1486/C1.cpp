#include <bits/stdc++.h>
using namespace std;

int query(int l, int r) {
    if (l == r) {
        return -1;
    }

    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int s = query(1, n), l, r;
    if (query(1, s) == s) {
        l = 1, r = s - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (query(m, s) == s) {
                l = m;
            } else {
                r = m - 1;
            }
        }
    } else {
        l = s + 1, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (query(s, m) == s) {
                r = m;
            } else {
                l = m + 1;
            }
        }
    }

    cout << "! " << l << "\n";
}