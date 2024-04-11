using namespace std;
#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define maxN 3005

int n, m, s1, t1, l1, s2, t2, l2, d[maxN][maxN], ans;
vector<int> ke[maxN];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    d[s][s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < ke[u].size(); ++i) {
            int v = ke[u][i];
            if (!d[s][v]) {
                d[s][v] = d[s][u]+1;
                q.push(v);
            }
        }
    }
    fto(u, 1, n) --d[s][u];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }
    scanf("%d%d%d", &s1, &t1, &l1);
    scanf("%d%d%d", &s2, &t2, &l2);

    fto(u, 1, n) BFS(u);

//    fto(u, 1, n) {
//        fto(v, 1, n) printf("%d ", d[u][v]);
//        printf("\n");
//    }

    int d1 = d[s1][t1], d2 = d[s2][t2];
    if (d1 <= l1 && d2 <= l2) ans = d1 + d2;
    else ans = m+1;
    fto(u, 1, n-1)
        fto(v, u+1, n)
            {
                d1 = min(d[s1][u]+d[u][v]+d[v][t1], d[s1][v]+d[v][u]+d[u][t1]);
                d2 = min(d[s2][u]+d[u][v]+d[v][t2], d[s2][v]+d[v][u]+d[u][t2]);
                if (d1 <= l1 && d2 <= l2) ans = min(ans, d1+d2-d[u][v]);
//                printf("%d %d %d %d %d\n", u, v, d1, d2, ans);
            }

    printf("%d", m-ans);

    return 0;
}