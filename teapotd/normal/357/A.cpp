#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,b,e) for(int i = (b); i < (e); i++)

int main() {
    cin.sync_with_stdio(0);

    int m; cin >> m;
    vector<int> elems(m);
    for (int& x : elems) cin >> x;

    int x, y; cin >> x >> y;

    rep(k, 1, m+1) {
        ll a = 0, b = 0;
        rep(i, 0, k-1) a += elems[i];
        rep(i, k-1, m) b += elems[i];

        if (a >= x && a <= y && b >= x && b <= y) {
            cout << k << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}