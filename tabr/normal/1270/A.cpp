#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        int ok = 0, ng = 0;
        rep(i, 0, a) {
            int x;
            cin >> x;
            ok = max(ok, x);
        }
        rep(i, 0, b) {
            int x;
            cin >> x;
            ng = max(ng, x);
        }
        if (ok > ng)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}