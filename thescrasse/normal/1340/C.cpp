// 1340C
// strada con zone sicure e semafori

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, d[10010], g, r, o[10010], dist[10010][1010], s1, s2, u1, u2;
bool visited[10010][1010];
deque<pair<ll, ll>> q;

void ins(ll s1, ll s2, ll u1, ll u2) {
    if (u2 == g) {
        if (visited[u1][0]) {
            return;
        }
        q.push_back({u1, 0});
        visited[u1][0] = true;
        dist[u1][0] = dist[s1][s2] + 1;
    } else if (u2 < g) {
        if (visited[u1][u2]) {
            return;
        }
        q.push_front({u1, u2});
        visited[u1][u2] = true;
        dist[u1][u2] = dist[s1][s2];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> d[i];
    }
    sort(d, d + m);
    for (i = 0; i < m - 1; i++) {
        o[i] = d[i + 1] - d[i];
    }
    cin >> g >> r;

    q.push_back({0, 0});
    visited[0][0] = true;
    dist[0][0] = 0;

    while (!q.empty()) {
        s1 = q.front().first; s2 = q.front().second; q.pop_front();
        // cout << s1 << ' ' << s2 << endl;
        if (s1 > 0) {
            u1 = s1 - 1; u2 = s2 + o[s1 - 1];
            ins(s1, s2, u1, u2);
        }
        if (s1 < m - 1) {
            u1 = s1 + 1; u2 = s2 + o[s1];
            ins(s1, s2, u1, u2);
        }
    }

    res = INF;
    for (i = 0; i < g; i++) {
        if (visited[m - 1][i]) {
            if (i == 0) {
                res = min(res, (g + r) * dist[m - 1][i] - r);
            } else {
                res = min(res, (g + r) * dist[m - 1][i] + i);
            }
        }
    }
    if (res == INF) {
        res = -1;
    }

    cout << res;

    return 0;
}