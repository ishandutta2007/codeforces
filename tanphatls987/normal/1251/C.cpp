#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        string s;
        vector<int> v[2];
        cin >> s;
        for(int i = s.length() - 1; i >= 0; i--) {
            int val = s[i] - '0';
            v[val % 2].push_back(val);
        }
        for(int i = 1; i <= s.length(); i++) {
            int dir = -1, val = 10;
            for(int j = 0; j <= 1; j++) if (!v[j].empty()) {
                if (val > v[j].back()) {
                    dir = j, val = v[j].back();
                }
            }
            cout << val;
            v[dir].pop_back();
        }
        cout << '\n';
    }
}