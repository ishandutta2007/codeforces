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

constexpr int INF = 1e9;

void run() {
    int t; cin >> t;

    while (t--) {
        int n, d; cin >> n >> d;
        Vi dist(n, INF);
        queue<int> que;

        rep(i, 0, n) {
            int e; cin >> e;
            if (e == 0) {
                dist[i] = 0;
                que.push(i);
            }
        }

        while (!que.empty()) {
            int i = que.front();
            que.pop();
            int j = (i+d) % n;
            if (dist[j] == INF) {
                dist[j] = dist[i]+1;
                que.push(j);
            }
        }

        int ans = *max_element(all(dist));
        cout << (ans != INF ? ans : -1) << '\n';
    }
}