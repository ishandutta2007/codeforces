#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

string vowel = "aeiou";

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    vector<string> ans(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i] += (i % 2 == j % 2 ? 'C' : '.');
            cnt += (ans[i][j] == 'C');
        }
    }

    cout << cnt << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}