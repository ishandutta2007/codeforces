#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
string s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s, s + n, [](const string& a, const string& b) {
        return a + b < b + a;
    });
    for (int i = 0; i < n; ++i) cout << s[i]; cout << endl;
    return 0;
}