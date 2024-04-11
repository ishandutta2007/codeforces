#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        set<char> distinct;
        for (auto c : s) distinct.insert(c);

        cout << s.size() + distinct.size() << "\n";
    }
}