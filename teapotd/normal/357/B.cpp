#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for(auto&a:(x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

vector<Vi> G;
vector<int> seen;

void dfs(int v) {
    if (seen[v]) return;
    bool ok[4] = {1,1,1,1};

    each(e, G[v]) {
        if (seen[e]) {
            ok[seen[e]] = 0;
        }
    }

    rep(i, 1, 4) if (ok[i]) {
        seen[v] = i;
        break;
    }

    each(e, G[v]) dfs(e);
}

int main() {
    cin.sync_with_stdio(0);

    int n, m; cin >> n >> m;
    G.resize(n);

    rep(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c--;
        G[a].pb(b);
        G[b].pb(a);
        G[a].pb(c);
        G[c].pb(a);
        G[b].pb(c);
        G[c].pb(b);
    }

    seen.resize(n);
    rep(i, 0, n) dfs(i);

    rep(i, 0, n) cout << seen[i] << ' ';
    cout << '\n';
    return 0;
}