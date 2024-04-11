#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s;
    t = s;

    vector<int> sol1, sol2;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'B') {
            sol1.push_back(i + 1);
            s[i + 1] = (s[i + 1] == 'B' ? 'W' : 'B');
        }
        if (t[i] == 'W') {
            sol2.push_back(i + 1);
            t[i + 1] = (t[i + 1] == 'B' ? 'W' : 'B');
        }
    }
    if (s.back() == 'B' && t.back() == 'W') {
        cout << -1 << '\n';
        exit(0);
    } else if (s.back() == 'B' || (t.back() == 'B' && sol1.size() > sol2.size())) {
        swap(sol1, sol2);
    }
    cout << sol1.size() << '\n';
    for (auto i : sol1) {
        cout << i << ' ';
    }
    cout << '\n';
}