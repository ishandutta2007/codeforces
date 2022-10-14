#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bal = 0;
    bool was = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') bal++;
        else {
            if (was == true) {
                was = false;
            } else {
                --bal;
            }
        }
        if (bal < 0) {
            cout << "No" << '\n';
            return 0;
        }
    }
    if (!was) --bal;
    if (bal == 0) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}