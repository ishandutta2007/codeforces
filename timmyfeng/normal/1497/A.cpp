#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        for (int i = 0; i < n; ++i) {
            auto it = find(a.begin(), a.end(), i);
            if (it == a.end()) {
                it = a.begin();
            }

            cout << *it << " ";
            a.erase(it);
        }
        cout << "\n";
    }
}