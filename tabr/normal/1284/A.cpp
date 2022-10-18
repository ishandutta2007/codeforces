#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, m) cin >> t[i];
    int q;
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        cout << s[(y - 1) % n] << t[(y - 1) % m] << endl;
    }
    return 0;
}