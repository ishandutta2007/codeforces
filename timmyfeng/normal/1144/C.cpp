#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> inc, dec;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        (inc.count(a) > 0 ? dec : inc).insert(a);
    }

    if ((int) (inc.size() + dec.size()) == n) {
        cout << "YES\n";
        cout << inc.size() << "\n";
        for (auto i : inc) {
            cout << i << " ";
        }
        cout << "\n";
        cout << dec.size() << "\n";
        for (auto it = dec.rbegin(); it != dec.rend(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}