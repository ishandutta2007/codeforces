#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int t[n];
    bool flag = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (i != 0 && t[i] != t[i - 1]) flag = 1;
        if (i != 0 && t[i] == t[i - 1]) pos = i - 1;
    }
    if (t[0] != t[n - 1]) flag = 1;
    if (t[0] == t[n - 1]) pos = -2;
    if (!flag) {
        cout << 1 << "\n";
        for (int i = 0; i < n; i++) cout << 1 << ' ';
        cout << "\n";
        return;
    }
    if (n % 2 == 0 || pos != -1) {
        cout << 2 << "\n";
        if (n % 2 == 0) pos = -1;
        int c = 1;
        for (int i = 0; i < n; i++) {
            cout << c << ' ';
            if (i != pos) c = 3 - c;
        }
        cout << "\n";
        return;
    }
    cout << 3 << "\n";
    cout << 3 << ' ';
    int c = 1;
    for (int i = 1; i < n; i++) {
        cout << c << ' ';
        c = 3 - c;
    }
    cout << "\n";
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}