using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 105

int q;
vector<ii> p;
bool visited[maxN];

bool canMove(ii a, ii b) {
    return ((b.fi < a.fi && a.fi < b.se) || (b.fi < a.se && a.se < b.se));
}

void DFS(int u) {
    visited[u] = true;
    fto(v, 0, p.size()-1)
        if (!visited[v] && canMove(p[u], p[v])) DFS(v);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &q);
    fto(i, 1, q) {
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 1) p.pb(mp(u, v));
        else {
            memset(visited, false, sizeof(visited));
            DFS(u-1);
            puts((visited[v-1]) ? "YES" : "NO");
        }
    }

    return 0;
}