#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    int ones = count(a.begin(), a.end(), 1);

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            if (a[x - 1] == 1) {
                --ones;
            } else {
                ++ones;
            }
            a[x - 1] ^= 1;
        } else {
            cout << (x <= ones ? 1 : 0) << "\n";
        }
    }
}