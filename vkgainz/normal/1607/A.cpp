#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<int> p(26);
        for (int i = 0; i < 26; i++) {
            p[s[i] - 'a'] = i;
        }
        string t; cin >> t;
        int ans = 0;
        for (int i = 1; i < t.length(); i++) {
            ans += abs(p[t[i] - 'a'] - p[t[i - 1] - 'a']);
        }
        cout << ans << "\n";
    }
}