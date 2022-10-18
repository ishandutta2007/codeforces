//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 6005
#define oo 1000000007
#define EPS 10e-9

int n, r[maxN], f[maxN][maxN], ans;
vector<int> ke[maxN];

int Solve(int u, int v) {
//    printf("u, n: %d %d\n", u, v);
    if (u == n+1) return 1;
    if (f[u][v] != -1) return f[u][v];
    queue<int> q;
    bool visited[maxN];
    memset(visited, false, sizeof visited);
    q.push(u);
    visited[v] = true;
    visited[u] = true;
    int res = 1;
//    printf("visited: ");
//    fto(u, 1, n) printf("%d ", visited[u]);
//    printf("\n");
    while (!q.empty()) {
        int y = q.front(); q.pop();
        forit(it, ke[y]) {
            int x = *it;
//            printf("u, v: %d %d; x, y: %d %d\n", u, v, x, y);
            if (!visited[x]) {
                visited[x] = true;
                if (r[y] < r[v]) res = max(res, Solve(x, y)+1);
                q.push(x);
            }
        }
    }
    return (f[u][v] = res);
}

int main() {
    scanf("%d", &n);
    fto(u, 1, n) scanf("%d", &r[u]);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }
    fto(u, 1, n) {
        if (ke[u].size() == 1) ke[u].pb(n+1);
    }

    fto(u, 1, n)
        fto(v, 1, n) f[u][v] = -1;

    fto(u, 1, n) {
        forit(it, ke[u]) {
            int v = *it;
            ans = max(ans, Solve(u, v));
        }
    }

//    fto(u, 1, n) {
//        fto(v, 1, n) printf("%d ", f[u][v]);
//        printf("\n");
//    }

    cout << ans;

    return 0;
}