// 1244F
// Chips

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dist[maxn];
string s;
char c[maxn];
bool visited[maxn];
vector<ll> adj[maxn], st;
queue<ll> q;

ll pv(ll x) {
    return (x + n - 1) % n;
}

ll nx(ll x) {
    return (x + 1) % n;
}

char ot(char c) {
    if (c == 'B') return 'W';
    else return 'B';
}

void bfs() {
    for (auto u : st) {
        visited[u] = true; dist[u] = 0; q.push(u);
    }

    while (!q.empty()) {
        ll s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true; dist[u] = dist[s] + 1;
            c[u] = c[s]; q.push(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k >> s;
    for (i = 0; i < n; i++) {
        c[i] = s[i]; dist[i] = INF;
        if (s[i] == s[pv(i)] || s[i] == s[nx(i)]) st.pb(i);
    }

    for (i = 0; i < n; i++) {
        adj[i].pb(pv(i)); adj[i].pb(nx(i));
    }

    bfs();

    for (i = 0; i < n; i++) {
        if (dist[i]<= k) cout << c[i];
        else if (k % 2) cout << ot(s[i]);
        else cout << s[i];
    }

    return 0;
}