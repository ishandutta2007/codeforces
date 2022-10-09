// 703D
// Mishka and Interesting sum

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res[1000010], flag, a[1000010], b, ps[1000010], fen[1000010], l, q, x, y;
map<ll, ll> last;
vector<array<ll, 3>> v;

void upd(ll x, ll pos) {
    while (pos <= n) {
        fen[pos] ^= x;
        pos += pos & -pos;
    }
}

ll rxor(ll l, ll r) {
    ll res; res = 0; l--;
    while (r > 0) {
        res ^= fen[r];
        r -= r & -r;
    }
    while (l > 0) {
        res ^= fen[l];
        l -= l & -l;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 1; i <= n; i++) {
        fen[i] = 0;
    }
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ps[0] = 0;
    for (i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] ^ a[i];
        // cout << ps[i] << ' ';
    }
    // cout << endl << flush;

    cin >> q;
    for (i = 0; i < q; i++) {
        cin >> x >> y;
        v.push_back({y, x, i});
    }

    sort(v.begin(), v.end());

    k = 0; l = 0;
    for (i = 1; i <= n; i++) {
        if (last.count(a[i])) {
            upd(a[i], last[a[i]]);
        }
        upd(a[i], i);
        last[a[i]] = i;
        while (l < q && v[l][0] == i) {
            res[v[l][2]] = rxor(v[l][1], v[l][0]) ^ (ps[v[l][1] - 1] ^ ps[v[l][0]]);
            l++;
        }
        /* for (j = 1; j <= n; j++) {
            cout << fen[j] << ' ';
        }
        cout << endl; */
    }

    for (i = 0; i < q; i++) {
        cout << res[i] << endl;
    }

    return 0;
}