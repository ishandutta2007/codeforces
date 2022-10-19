#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

vector<int> adj[MN];
int p[MN], dep[MN], nxt[MN];
void dfs(int v){
    dep[v] = 1;
    for (int to : adj[v]){
        if (to == p[v]) continue;
        p[to] = v;
        dfs(to);
        if (dep[to] + 1 > dep[v]){
            nxt[v] = to;
            dep[v] = dep[to] + 1;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    struct Item{
        int sz, v;
        bool operator<(const Item &x) const{
            return sz < x.sz;
        }
    };
    dfs(1);
    priority_queue<Item> pq; pq.push({dep[1], 1});
    int b = N, r = 0;
    while (!pq.empty() && r < K){
        auto [sz, v] = pq.top(); pq.pop();
        r++; b -= sz;
        while (v){
            for (int to : adj[v]){
                if (to == p[v] || to == nxt[v]) continue;
                pq.push({dep[to], to});
            }
            v = nxt[v];
        }
    }
    if (r < K){
        ll ans = 1LL * (N - r - b) * (r - b);
        for (int i = r + 1; i <= K; ++i){
            ans = max(ans, 1LL * (N - i) * i);
        }
        cout << ans << '\n';
    }
    else{
        ll ans = LLONG_MAX;
        for (int i = b; i >= 0; --i){
            ans = min(ans, 1LL * (N - r - i) * (r - i));
        }
        cout << ans << '\n';
    }
}