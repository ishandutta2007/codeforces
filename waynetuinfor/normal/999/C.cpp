#include <bits/stdc++.h>
using namespace std;

deque<int> pos[26];

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < s.size(); ++i) pos[s[i] - 'a'].push_back(i);
    while (k--) {
        for (int i = 0; i < 26; ++i) if (pos[i].size()) {
            pos[i].pop_front();
            break;
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < 26; ++i) {
        for (int j : pos[i]) ans.emplace_back(j, i);
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << (char)(i.second + 'a');
    cout << endl;
}