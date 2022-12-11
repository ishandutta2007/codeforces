#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    string s, t;
    s.resize(n);
    t.resize(n);
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        int c = x[i] - '0'; 
        if (!flag) {
            if (c == 0) {
                s[i] = t[i] = '0';
            }
            if (c == 1) {
                s[i] = '0';
                t[i] = '1';
            }
            if (c == 2) {
                s[i] = '1';
                t[i] = '1';
            }
            if (s[i] != t[i]) flag = 1;
        } else {
            if (c == 0) {
                s[i] = t[i] = '0';
            }
            if (c == 1) {
                t[i] = '0';
                s[i] = '1';
            }
            if (c == 2) {
                t[i] = '0';
                s[i] = '2';
            }
        }
    }
    cout << s << "\n" << t << "\n";
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}