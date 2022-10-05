//
// Created by Danny Mittal on 6/30/19.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    string s;
    cin >> s;
    vector<int> lens[26];
    for (int i = 0; i < 26; i++) {
        lens[i].push_back(0);
    }
    for (int i = 1; i <= n; i++) {
        lens[s[i - 1] - 'a'].push_back(i);
    }
    cin >> m;
    int amt[26];
    for (int i = 1; i <= m; i++) {
        memset(amt, 0, 26 * sizeof(int));
        string t;
        cin >> t;
        for (char chara : t) {
            amt[chara - 'a']++;
        }
        int res = 0;
        for (int j = 0; j < 26; j++) {
            res = max(res, lens[j][amt[j]]);
        }
        cout << res << "\n";
    }
    cout << flush;
}