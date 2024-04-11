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

        set<int> flavors;
        while (n--) {
            int a;
            cin >> a;
            flavors.insert(a);
        }

        int max = *flavors.rbegin();

        if (max % 3 == 0) {
            cout << max / 3 + ranges::any_of(flavors, [](int i) { return i % 3 != 0; }) << "\n";
        } else if (max % 3 == 1) {
            if (!flavors.contains(max - 1) && !flavors.contains(1)) {
                cout << max / 3 + 1 << "\n";
            } else if (!ranges::any_of(flavors, [](int i) { return i % 3 == 2; })) {
                cout << max / 3 + 1 << "\n";
            } else {
                cout << max / 3 + 2 << "\n";
            }
        } else if (max % 3 == 2) {
            cout << max / 3 + 1 + ranges::any_of(flavors, [](int i) { return i % 3 == 1; }) << "\n";
        }
    }
}