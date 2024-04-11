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
    int n, m; cin >> n >> m;
    vector<ll> trees(n);
    each(t, trees) cin >> t;

    map<ll, ll> dist;
    queue<ll> que;

    each(t, trees) {
        dist[t] = 0;
        que.push(t);
    }

    vector<ll> ans;
    ll distSum = 0;

    while (sz(ans) < m) {
        ll pos = que.front();
        ll d = dist[pos];
        que.pop();

        if (d != 0) {
            distSum += d;
            ans.pb(pos);
        }

        for (ll e : {pos-1, pos+1}) {
            if (!dist.count(e)) {
                dist[e] = d+1;
                que.push(e);
            }
        }
    }
    
    cout << distSum << '\n';
    each(e, ans) cout << e << ' ';
    cout << '\n';
}