#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a1, a2, pos1, pos2, c1, c2;
    a1 = a2 = pos1 = pos2 = c1 = c2 = 0;
    rep(i, 1, k + 2) {
        cout << "? ";
        rep(j, 1, k + 2) if (i != j) cout << j << ' ';
        cout << endl;
        int pos, b;
        cin >> pos >> b;
        if (i == 1) {
            pos1 = pos;
            a1 = b;
        } else if (pos != pos1) {
            pos2 = pos;
            a2 = b;
        }
        if (pos1 == pos) {
            c1++;
        } else
            c2++;
    }
    cout << "! ";
    if (a1 > a2)
        cout << c1 << endl;
    else
        cout << c2 << endl;
    return 0;
}