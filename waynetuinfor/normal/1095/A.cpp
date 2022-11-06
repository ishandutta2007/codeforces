#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int p = 1;
    while (p * (p + 1) / 2 < n) p++;
    for (int i = 0, j = 1; j <= p; i += j, ++j) {
        cout << s[i];
    }
    cout << endl;
}