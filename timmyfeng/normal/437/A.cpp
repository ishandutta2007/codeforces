#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> s(4);
    for (auto &i : s) {
        cin >> i;
    }

    sort(s.begin(), s.end(), [&](string a, string b) {
        return a.size() < b.size();
    });

    bool small = 2 * (s[0].size() - 2) <= s[1].size() - 2;
    bool large = 2 * (s[2].size() - 2) <= s[3].size() - 2;

    if (small ^ large ^ true) {
        cout << "C\n";
    } else if (small) {
        cout << s[0][0] << "\n";
    } else {
        cout << s[3][0] << "\n";
    }
}