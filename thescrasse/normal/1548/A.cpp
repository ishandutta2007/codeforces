#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll q, ty;
set<ll> adj[maxn];

void ins(ll a, ll b) {
    if (!adj[a].empty()) {
        auto it1 = adj[a].end(); it1--;
        if ((*it1) < a) res--;
    } else {
        res--;
    }
    if (!adj[b].empty()) {
        auto it2 = adj[b].end(); it2--;
        if ((*it2) < b) res--;
    } else {
        res--;
    }
    adj[a].insert(b); adj[b].insert(a);
    auto it = adj[a].end(); it--;
    if ((*it) < a) res++;
    it = adj[b].end(); it--;
    if ((*it) < b) res++;
}

void rm(ll a, ll b) {
    auto it = adj[a].end(); it--;
    if ((*it) < a) res--;
    it = adj[b].end(); it--;
    if ((*it) < b) res--;
    adj[a].erase(b); adj[b].erase(a);
    if (!adj[a].empty()) {
        it = adj[a].end(); it--;
        if ((*it) < a) res++;
    } else {
        res++;
    }
    if (!adj[b].empty()) {
        it = adj[b].end(); it--;
        if ((*it) < b) res++;
    } else {
        res++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m; res = n;
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        ins(a, b);
        // cout << res << nl;
    }

    cin >> q;
    while (q--) {
        cin >> ty;
        if (ty == 1) {
            cin >> a >> b;
            ins(a, b);
            // cout << res << nl;
        } else if (ty == 2) {
            cin >> a >> b;
            rm(a, b);
            // cout << res << nl;
        } else {
            cout << res << nl;
        }
    }

    return 0;
}