#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

int i, i1, j, k, k1, t, n, m, res, check1, a, b, q, fen[1000010], bsl, bsu, bsm;

void upd(int x, int pos) {
    while (pos <= n) {
        fen[pos] += x;
        pos += pos & -pos;
    }
}

int rsum(int pos) {
    int res;
    res = 0;
    while (pos > 0) {
        // cout << pos << endl << flush;
        res += fen[pos];
        pos -= pos & -pos;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    
    for (i = 0; i <= 1000000; i++) {
        fen[i] = 0;
    }

    cin >> n >> q;
    for (i = 0; i < n; i++) {
        // cout << i << endl << flush;
        cin >> a;
        upd(1, a);
    }
    for (i = 0; i < q; i++) {
        // cout << i << endl << flush;
        cin >> k;
        if (k > 0) {
            upd(1, k);
        } else {
            k *= -1;
            bsl = 0; bsu = n;
            while (bsl < bsu) {
                // cout << bsl << ' ' << bsu << endl << flush;
                bsm = (bsl + bsu) / 2;
                if (rsum(bsm) >= k) {
                    bsu = bsm;
                } else {
                    bsl = bsm + 1;
                }
            }
            upd(-1, bsl);
        }
    }

    if (rsum(n) == 0) {
        cout << 0;
    } else {
        for (i = 1; i <= n; i++) {
            if (fen[i] > 0) {
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}