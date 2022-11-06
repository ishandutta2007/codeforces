#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int c = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 'U' && s[i + 1] == 'R') {
            ++c;
            ++i;
        } else if (s[i] == 'R' && s[i + 1] == 'U') {
            ++c;
            ++i;
        }
    }
    cout << n - c << endl;
}