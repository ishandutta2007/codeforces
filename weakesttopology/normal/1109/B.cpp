#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = (int)size(s);
    if (count(begin(s), begin(s) + n / 2, s[0]) == n / 2) {
        cout << "Impossible" << endl;
        exit(0);
    }
    int ans = 2;
    for (int x = 1; x < n; ++x) {
        string r(begin(s) + x, end(s));
        r += string(begin(s), begin(s) + x);
        auto rrev = r;
        reverse(begin(rrev), end(rrev));
        if (r != s && rrev == r) {
            ans = 1;
            break;
        }
    }
    cout << ans << endl;
    exit(0);
}