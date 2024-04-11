#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        bool zeroes = false;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x == 0) zeroes = true;
            else a.push_back(x);
        }
        if (zeroes) a.push_back(0);

        if (a.size() > 5) {
            cout << "NO\n";
            continue;
        }

        bool closed = true;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = i + 1; j < a.size(); ++j) {
                for (int k = j + 1; k < a.size(); ++k) {
                    closed &= !!count(a.begin(), a.end(), a[i] + a[j] + a[k]);
                }
            }
        }

        cout << (closed ? "YES" : "NO") << "\n";
    }
}