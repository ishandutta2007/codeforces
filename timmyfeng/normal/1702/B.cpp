#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        int answer = 0;
        for (int i = 0, j = 0; i < (int) s.size(); i = j) {
            set<char> letters;
            while (j < (int) s.size() && (letters.size() < 3u || letters.count(s[j]))) {
                letters.insert(s[j++]);
            }
            ++answer;
        }

        cout << answer << "\n";
    }
}