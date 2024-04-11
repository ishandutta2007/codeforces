#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b; --a; --b;
    int t = 0;
    while (n) ++t, n >>= 1; --t;
    vector<int> va, vb;
    for (int i = 0; i < t; ++i) va.push_back(a & 1), a >>= 1;
    for (int i = 0; i < t; ++i) vb.push_back(b & 1), b >>= 1;
    // for (int i : va) cout << i << ' '; cout << endl;
    // for (int i : vb) cout << i << ' '; cout << endl;
    int ans = -1;
    for (int i = t - 1; i >= 0 && ans == -1; --i) {
        if (va[i] != vb[i]) ans = i + 1;
    }
    if (ans == t) cout << "Final!" << endl;
    else cout << ans << endl;
    return 0;
}