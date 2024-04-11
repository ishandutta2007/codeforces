#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> pos;
    while (t--) {
        int n;
        cin >> n;
        pos.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            pos[a] = i;
        }

        int lo = n - 1, hi = 0;
        for (int i = 1; i <= n; ++i) {
            lo = min(lo, pos[i]);
            hi = max(hi, pos[i]);
            cout << (hi - lo + 1 == i);
        }
        cout << '\n';
    }
}