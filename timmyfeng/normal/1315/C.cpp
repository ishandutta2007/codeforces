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
        vector<int> b(n);
        set<int> hat;
        for (int i = 1; i <= 2 * n; i++) {
            hat.insert(i);
        }
        for (auto& i : b) {
            cin >> i;
            hat.erase(i);
        }

        vector<int> sol(2 * n);
        for (int i = 0; i < n; i++) {
            auto it = hat.lower_bound(b[i]);
            if (it == hat.end()) break;
            sol[i * 2] = b[i];
            sol[i * 2 + 1] = *it;
            hat.erase(it);
        }
        if (sol.back()) {
            for (auto i : sol) {
                cout << i << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
}