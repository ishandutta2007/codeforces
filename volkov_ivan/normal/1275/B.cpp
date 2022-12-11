#include <iostream>

using namespace std;

void solve() {
    string s;
    cin >> s;
    bool f0 = 0, fch = 0;
    int summ = 0;
    for (int i = 0; i < (int) s.length(); i++) {
        if (f0 && s[i] == '0') fch = 1;
        if (s[i] == '0') f0 = 1;
        if (s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8') fch = 1;
        summ += s[i] - '0';
    }
    if (summ % 3 == 0 && f0 && fch) {
        cout << "red" << endl;
    } else {
        cout << "cyan" << endl;
    }
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) solve();
    return 0;
}