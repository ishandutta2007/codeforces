#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

inline void cng(char &x) {
    if (x == 'B')
        x = 'W';
    else
        x = 'B';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    string b = s, w = s;
    vector<int> ab, aw;
    rep(i, 0, n - 1) {
        if (b[i] == 'W') {
            ab.push_back(i + 1);
            cng(b[i]);
            cng(b[i + 1]);
        }
        if (w[i] == 'B') {
            aw.push_back(i + 1);
            cng(w[i]);
            cng(w[i + 1]);
        }
    }
    if (b[n - 1] == 'B') {
        cout << ab.size() << endl;
        for (auto x : ab)
            cout << x << ' ';
        cout << endl;
    } else if (w[n - 1] == 'W') {
        cout << aw.size() << endl;
        for (auto x : aw)
            cout << x << ' ';
        cout << endl;
    } else
        cout << -1 << endl;

    return 0;
}