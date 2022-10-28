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
        bool ok = false;
        vector<int> first(n + 1, -1);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (first[a] != -1) {
                if (i - first[a] > 1) {
                    ok = true;
                }
            } else {
                first[a] = i;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}