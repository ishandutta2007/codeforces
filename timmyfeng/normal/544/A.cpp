#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    string s;
    cin >> k >> s;

    vector<string> strings;
    set<char> used;
    for (auto c : s) {
        if (used.count(c) == 0) {
            used.insert(c);
            strings.push_back("");
        }
        strings.back() += c;
    }

    if ((int) strings.size() < k) {
        cout << "NO\n";
        exit(0);
    }

    cout << "YES\n";

    for (int i = 0; i < k - 1; ++i) {
        cout << strings[i] << "\n";
    }

    string last;
    for (int i = k - 1; i < (int) strings.size(); ++i) {
        last += strings[i];
    }

    cout << last << "\n";
}