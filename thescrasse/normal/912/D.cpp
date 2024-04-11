// 912D
// valore atteso max numero pesci in un quadrato k * k

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, r, v, p1[100010], p2[100010], m1, m2;
array<ll, 3> o;
priority_queue<array<ll, 3>> pq;
map<pair<ll, ll>, bool> visited;
long double resf;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ll d1[4] = {1, 0, -1, 0};
    ll d2[4] = {0, 1, 0, -1};

    cin >> n >> m >> r >> k;

    for (i = 0; i < n; i++) {
        p1[i] = min({r - 1, n - r, i, n - i - 1}) + 1;
    }
    for (i = 0; i < m; i++) {
        p2[i] = min({r - 1, m - r, i, m - i - 1}) + 1;
    }

    res = 0;
    pq.push({p1[n / 2] * p2[m / 2], n / 2, m / 2});
    visited[{n / 2, m / 2}] = true;
    while (k--) {
        o = pq.top();
        v = o[0]; a = o[1]; b = o[2]; pq.pop();
        // cout << v << ' ' << a << ' ' << b << endl;
        res += v;
        for (i = 0; i < 4; i++) {
            m1 = d1[i]; m2 = d2[i];
            if (a + m1 >= 0 && a + m1 < n && b + m2 >= 0 && b + m2 < m) {
                if (!visited[{a + m1, b + m2}]) {
                    visited[{a + m1, b + m2}] = true;
                    pq.push({p1[a + m1] * p2[b + m2], a + m1, b + m2});
                }
            }
        }
    }

    resf = (long double)res / ((n - r + 1) * (m - r + 1));
    cout << fixed << setprecision(20);
    cout << resf;

    return 0;
}