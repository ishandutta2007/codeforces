#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

using namespace std;
using vi = vector<int>;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vi w(n), s(n); for(int& x : w) cin >> x;
    vector<vi> g(n); vi x(m), u(n), y(m), ans;
    for(int a, b, i = 0; i < m; ++i) {
        cin >> a >> b; ++s[a-1], ++s[b-1];
        g[a-1].pb(i), g[b-1].pb(i); x[i] = (a-1)^(b-1);
    }

    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(s[i] > w[i]) continue;
        q.push(i); u[i] = 1;
    }

    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int i : g[v]) {
            if(y[i]) continue;
            ans.pb(i), y[i] = 1;
            const int to = v ^ x[i];
            --s[to];
            if(s[to] <= w[to] && !u[to]) q.push(to), u[to] = 1;
        }
    }

    if(ans.size() < m) cout << "DEAD" << endl;
    else {
        cout << "ALIVE" << endl;
        for(int i =  m ; i--; ) cout << ans[i]+1 << ' ';
        cout <<  endl;
    }
}