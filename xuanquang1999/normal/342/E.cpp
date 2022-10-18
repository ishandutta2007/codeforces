//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define BASE 316
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, k, in[maxN], out[maxN], d[maxN], l2[2*maxN], b[20][2*maxN], cur[maxN];
vector<int> ke[maxN], lis, recent;

void DFS(int u, int p) {
    in[u] = out[u] = lis.size(); lis.pb(d[u]);
    forit(it, ke[u]) {
        int v = *it;
        if (v == p) continue;
        d[v] = d[u]+1;
        DFS(v, u);
        out[u] = lis.size(); lis.pb(d[u]);
    }
}

void BFS() {
    vector<int> d(n+1, 0);
    queue<int> q;
    forit(it, recent) d[*it] = 1, q.push(*it);
    recent.clear();
    while (!q.empty()) {
        int u = q.front(); q.pop();
        forit(it, ke[u]) {
            int v = *it;
            if (!d[v]) {
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    fto(u, 1, n) cur[u] = min(cur[u], d[u]-1);
}

void build() {
    k = l2[lis.size()];
    fto(j, 0, lis.size()-1) b[0][j] = lis[j];
    fto(i, 1, k) {
        fto(j, 0, lis.size()-(1<<i)) b[i][j] = min(b[i-1][j], b[i-1][j+(1<<(i-1))]);
    }
}

int query(int l, int r) {
    int k = l2[r-l+1];
    return min(b[k][l], b[k][r-(1<<k)+1]);
}

int LCA(int u, int v) {
    return d[u]+d[v]-2*query(min(in[u], in[v]), max(out[u], out[v]));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    DFS(1, -1);

    fto(i, 1, lis.size()) l2[i] = log2(i);
    build();

    recent.pb(1);
    fto(u, 1, n) cur[u] = oo;
    fto(i, 1, m) {
        int t, u; scanf("%d%d", &t, &u);
        if (t == 1) {
            recent.pb(u);
            if (recent.size() >= BASE) BFS();
        } else {
            int ans = cur[u];
            forit(it, recent) {
                int v = *it;
                ans = min(ans, LCA(u, v));
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}