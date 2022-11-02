#include <bits/stdc++.h>
using namespace std;

string s[50010];

bool cmp (string a, string b) {
    return a + b < b + a;
}

int main () {
    ios::sync_with_stdio (0);
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort (s + 1, s + 1 + n, cmp);
    for (int i = 1; i <= n; i++) cout << s[i];
}