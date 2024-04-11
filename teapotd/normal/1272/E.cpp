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

void run() {
    int n; cin >> n;
    vector<Vi> G(n);
    vector<bool> side(n);

    rep(i, 0, n) {
        int a; cin >> a;
        side[i] = a%2;
        if (i-a >= 0) G[i-a].pb(i);
        if (i+a < n) G[i+a].pb(i);
    }

    Vi dist[2];
    queue<int> que;

    rep(d, 0, 2) {
        dist[d].resize(n, INT_MAX);

        rep(i, 0, n) {
            if (side[i] == d) {
                dist[d][i] = 0;
                que.push(i);
            }
        }

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            each(e, G[v]) {
                if (dist[d][e] == INT_MAX) {
                    dist[d][e] = dist[d][v]+1;
                    que.push(e);
                }
            }
        }
    }

    rep(i, 0, n) {
        int k = dist[!side[i]][i];
        cout << (k != INT_MAX ? k : -1) << ' ';
    }
    cout << '\n';
}