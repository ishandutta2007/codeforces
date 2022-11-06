#include <bits/stdc++.h>
using namespace std;

int c[2];

int main() {
    string s; cin >> s;
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') pos.push_back(i);
    }
    if (pos.size() < 6) return cout << "no" << endl, 0;
    // for (int i = pos[pos.size()])
    int p = pos[pos.size() - 6];
    for (int i = 0; i < p; ++i) {
        if (s[i] == '1') return cout << "yes" << endl, 0;
    }
    cout << "no" << endl;
    return 0;
}