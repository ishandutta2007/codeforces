//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 405

int n, m, a[maxN][maxN], dT[maxN], dB[maxN];

void BFS(int f, int d[], int x) {
    queue<int> q;
    q.push(f);
    memset(d, 0, sizeof d);
    d[f] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        fto(v, 1, n)
            if (a[u][v] == x && !d[v]) {
                d[v] = d[u]+1;
                q.push(v);
            }
    }
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
        a[u][v] = a[v][u] = 1;
    }
    BFS(1, dT, 1);
    BFS(1, dB, 0);

    if (dT[n] == 0 || dB[n] == 0) puts("-1");
    else printf("%d", max(dT[n], dB[n])-1);

    return 0;
}