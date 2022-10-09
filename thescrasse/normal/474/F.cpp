// 474F
// query con gcd in un range

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (long long)1e18

long long i, i1, j, k, k1, t, n, m, q, res, check1, a, b, g, s[300010], l, r;
vector<long long> adj[100010];
map<long long, long long> enc;

long long gcd(long long a, long long b) {
    if (a == -1) {
        return b;
    }
    if (a == b) {
        return a;
    }
    if (a < b) {
        swap(a, b);
    }
    a = (a + b - 1) % b; a++;
    return gcd(a, b);
}

long long rmq(long long l, long long r) {
    // cout << l << ' ' << r << endl;
    long long res;
    res = -1;
    l += 131072; r += 131072;
    while (l < r) {
        if (l % 2 == 1) {
            res = gcd(res, s[l]);
            // cout << res << endl;
            l++;
        }
        if (r % 2 == 0) {
            res = gcd(res, s[r]);
            // cout << res << endl;
            r--;
        }
        l /= 2; r /= 2;
    }
    if (l == r) {
        res = gcd(res, s[l]);
    }
    // cout << res << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        s[i + 131072] = a;
        if (!enc.count(a)) {
            enc[a] = i;
        }
        adj[enc[a]].push_back(i);
    }

    for (i = n + 131072; i < 262144; i++) {
        s[i] = 1;
    }
    for (i = 131071; i >= 1; i--) {
        s[i] = gcd(s[2 * i], s[2 * i + 1]);
        /* if (s[2 * i] != 1 || s[2 * i + 1] != 1) {
            cout << i << ' ' << s[i] << endl;
        } */
    }

    for (i = 0; i < 100010; i++) {
        adj[i].push_back(INF);
    }

    cin >> q;
    while (q--) {
        cin >> l >> r;
        l--; r--;
        res = r - l + 1;
        g = rmq(l, r);
        // cout << l << ' ' << r << ' ' << g << endl;
        // cout << g << endl;
        if (!enc.count(g)) {
            cout << res << endl;
            continue;
        }
        a = enc[g];
        // cout << "a = " << a << endl;
        /* for (auto u : adj[a]) {
            cout << u << ' ';
        }
        cout << endl; */
        res += (lower_bound(adj[a].begin(), adj[a].end(), l) - adj[a].begin());
        res -= (upper_bound(adj[a].begin(), adj[a].end(), r) - adj[a].begin());
        // cout << (lower_bound(adj[a].begin(), adj[a].end(), l) - adj[a].begin()) << ' ' << (upper_bound(adj[a].begin(), adj[a].end(), r) - adj[a].begin()) << endl;
        cout << res << endl;
        // cout << "--------------" << endl;
    }

    return 0;
}