#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        cout << string(i, '(') << string(i, ')') << string(n-i, '(') << string(n-i, ')') << endl;
    }
}