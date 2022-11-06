#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    string t; cin >> t;
    string s = t;
    for (int i = 0; i < k - 1; ++i) {
        int p = 0;
        for (int j = 1; j < t.size(); ++j) {
            if (s.substr(s.size() - j, j) == t.substr(0, j)) p = j;
        }
        for (int j = p; j < t.size(); ++j) s += t[j];
    }
    cout << s << endl;
}