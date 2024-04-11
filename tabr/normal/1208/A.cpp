#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    rep(q, 0, t) {
        int a, b, n;
        cin >> a >> b >> n;
        if (n % 3 == 0)
            cout << a << endl;
        else if (n % 3 == 1)
            cout << b << endl;
        else
            cout << (a ^ b) << endl;
    }

    return 0;
}