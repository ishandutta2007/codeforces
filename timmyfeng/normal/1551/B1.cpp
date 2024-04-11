#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int ans = 0;
        map<char, int> tally;

        for (char c : s) {
            if (++tally[c] <= 2) {
                ++ans;
            }
        }

        cout << ans / 2 << "\n";
    }
}