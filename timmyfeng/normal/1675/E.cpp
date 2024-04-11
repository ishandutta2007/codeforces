#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        set<char> letters;
        for (char i = 'a'; i <= 'z'; ++i) {
            letters.insert(i);
        }

        for (auto &c : s) {
            c = *--letters.upper_bound(c);
            while (c != 'a' && letters.count(c) && k) {
                --k;
                letters.erase(c);
                c = *--letters.upper_bound(c);
            }
        }

        cout << s << "\n";
    }
}