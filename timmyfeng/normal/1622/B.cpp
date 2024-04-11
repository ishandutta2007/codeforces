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

        vector<pair<int, int>> p(n);
        for (int j = 0; auto &i : p) {
            cin >> i.first;
            i.second = j++;
        }
        ranges::sort(p);

        string s;
        cin >> s;

        vector<int> q(n); int ptr = 0;
        for (auto c : {'0', '1'}) {
            for (auto [i, j] : p) {
                if (s[j] == c) {
                    q[j] = ++ptr;
                }
            }
        }

        for (auto &i : q) cout << i << " ";
        cout << "\n";
    }
}