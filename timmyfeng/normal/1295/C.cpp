#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        vector<vector<int>> nxt(26, vector<int>(s.size() + 1, -1));
        for (int i = 0; i < s.size(); i++) {
            nxt[s[i] - 'a'][i] = i + 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (nxt[j][i] == -1) {
                    nxt[j][i] = nxt[j][i + 1];
                }
            }
        }
        int sol = 1;
        int ndx = 0;
        for (char c : t) {
            if (nxt[c - 'a'][0] == -1) {
                sol = -1;
                break;
            } else if (nxt[c - 'a'][ndx] == -1) {
                sol++;
                ndx = nxt[c - 'a'][0];
            } else {
                ndx = nxt[c - 'a'][ndx];
            }
        }
        cout << sol << '\n';
    }
}