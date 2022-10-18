#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    string s;
    while (t--) {
        ll n;
        cin >> n;
        ll len = 2;
        while (len * (len + 1) / 2 <= n)
            len++;
        n -= len * (len - 1) / 2;
        s = "133";
        rep(i, 0, n) s += '7';
        rep(i, 2, len) s += '3';
        s += '7';
        cout << s << endl;
    }

    return 0;
}