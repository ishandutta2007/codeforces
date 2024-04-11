// 1304E
// 1-trees e query
// idee:

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000000010

long long i, i1, j, k, k1, n, m, t, res, check1, a, b, x, y, p2, dist[100010], q, pos1[100010], pos2[100010], sz;
pair<long long, long long> segm[1000010];
vector<long long> adj[100010];
vector<pair<long long, long long>> pp;

void lpp(long long s, long long d) {
    // cout << s << ' ' << d << endl;
    if (dist[s] != -1) {
        return;
    }
    dist[s] = d;
    pp.push_back({d, s});
    sz = pp.size();
    pos1[s] = min(pos1[s], sz - 1);
    pos2[s] = max(pos2[s], sz - 1);
    for (auto u : adj[s]) {
        if (dist[u] == -1) {
            lpp(u, d + 1);
            pp.push_back({dist[s], s});
            sz = pp.size();
            pos1[s] = min(pos1[s], sz - 1);
            pos2[s] = max(pos2[s], sz - 1);
        }
    }
}

pair<long long, long long> rmin(long long a, long long b) {
    a += p2;
    b += p2;
    // cout << a << ' ' << b << endl;
    pair<long long, long long> m;
    m = {INF, -1};
    while (a <= b) {
        if (a % 2 == 1) {
            m = min(m, segm[a]);
            a++;
        }
        if (b % 2 == 0) {
            m = min(m, segm[b]);
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return m;
}

long long lcad(long long a, long long b) {
    if (pos1[a] > pos2[b]) {
        swap(a, b);
    }
    long long a1 = pos1[a];
    long long b1 = pos2[b];
    long long c = rmin(a1, b1).second;
    return dist[a] + dist[b] - 2 * dist[c];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (i = 1; i <= n; i++) {
        dist[i] = -1;
        pos1[i] = INF;
        pos2[i] = -1;
    }

    lpp(1, 0);
    /* for (auto u : pp) {
        cout << u.first << ' ' << u.second << endl;
    } */

    p2 = 1;
    while (p2 <= 2 * n - 1) {
        p2 *= 2;
    }
    // cout << p2 << endl;
    for (i = p2; i < 2 * p2; i++) {
        if (i - p2 < 2 * n - 1) {
            segm[i] = {pp[i - p2].first, pp[i - p2].second};
        } else {
            segm[i] = {INF, -1};
        }
    }
    for (i = p2 - 1; i >= 0; i--) {
        segm[i] = min(segm[2 * i], segm[2 * i + 1]);
    }

    /* for (i = 0; i < 2 * p2; i++) {
        cout << segm[i].first << ' ' << segm[i].second << endl;
    } */

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << i << ' ' << j << ' ' << lcad(i, j) << endl;
        }
    } */

    cin >> q;
    for (i1 = 0; i1 < q; i1++) {
        cin >> x >> y >> a >> b >> k;
        check1 = 0;
        // cout << lcad(a, b) << ' ' << lcad(a, x) + lcad(b, y) + 1 << ' ' << lcad(a, y) + lcad(b, x) + 1 << endl;
        if (lcad(a, b) <= k && (k - lcad(a, b)) % 2 == 0) {
            check1 = 1;
        }
        if (lcad(a, x) + lcad(b, y) + 1 <= k && (k - (lcad(a, x) + lcad(b, y) + 1)) % 2 == 0) {
            check1 = 1;
        }
        if (lcad(a, y) + lcad(b, x) + 1 <= k && (k - (lcad(a, y) + lcad(b, x) + 1)) % 2 == 0) {
            check1 = 1;
        }
        if (check1 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}