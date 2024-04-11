#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

vector<Vi> G;

Vi bfs(int src) {
    Vi dist(sz(G), -1);
    queue<int> que;

    dist[src] = 0;
    que.push(src);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        each(e, G[v]) {
            if (dist[e] == -1) {
                dist[e] = dist[v]+1;
                que.push(e);
            }
        }
    }

    return dist;
}

vector<Pii> elems;

bool check(int m) {
    vector<pair<Pii, Pii>> events;
    int id = 0;

    each(e, elems) {
        events.pb({ e, {1, id} });
        events.pb({ {m-e.y, m-e.x}, {0, id} });
        id++;
    }

    sort(all(events));
    reverse(all(events));

    int high1 = -1e9, high2 = -1e9;
    int id1 = -1, id2 = -1;

    each(e, events) {
        if (e.y.x) {
            if (e.x.y >= high1) {
                high2 = high1;
                id2 = id1;
                high1 = e.x.y;
                id1 = e.y.y;
            } else if (e.x.y > high2) {
                high2 = e.x.y;
                id2 = e.y.y;
            }
        } else {
            if (e.x.y <= high1 && e.y.y != id1) {
                return 1;
            }
            if (e.x.y <= high2 && e.y.y != id2) {
                return 1;
            }
        }
    }

    return 0;
}

int solve(int end) {
    int begin = 0;
    while (begin+1 < end) {
        int mid = (begin+end) / 2;
        if (check(mid)) {
            begin = mid;
        } else {
            end = mid;
        }
    }
    return begin+1;
}

void run() {
    int n, m, k; cin >> n >> m >> k;

    Vi special(k);
    each(s, special) {
        cin >> s;
        s--;
    }

    G.resize(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    Vi sDist = bfs(0);
    Vi tDist = bfs(n-1);

    elems.resize(k);
    rep(i, 0, k) {
        int s = special[i];
        elems[i] = {sDist[s], tDist[s]};
    }

    int ans = solve(n+15);
    ans = min(ans, sDist[n-1]);
    cout << ans << endl;
}