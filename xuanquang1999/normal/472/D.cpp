//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 2005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, c[maxN][maxN], d[maxN], trace[maxN];
ll f[maxN];
bool avail[maxN];
vector<int> ke[maxN];

void DFS(int u) {
    avail[u] = false;
    forit(it, ke[u]) {
        int v = *it;
        if (avail[v]) {
            f[v] = f[u]+c[u][v];
            DFS(v);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        fto(j, 1, n) {
            scanf("%d", &c[i][j]);
        }
    }

    fto(i, 1, n) {
        if (c[i][i] != 0) {
            puts("NO");
            return 0;
        }
    }
    fto(i, 1, n-1) {
        fto(j, i+1, n) {
            if (c[i][j] == 0 || c[i][j] != c[j][i]) {
                puts("NO");
                return 0;
            }
        }
    }

    fto(u, 1, n) d[u] = oo;
    d[1] = 0;
    memset(avail, true, sizeof avail);
    while (true) {
        int u = 0, minD = oo;
        fto(v, 1, n) {
            if (avail[v] && d[v] < minD) {
                minD = d[v];
                u = v;
            }
        }
        if (u == 0) break;
        avail[u] = false;
        fto(v, 1, n) {
            if (avail[v] && d[v] > c[u][v]) {
                d[v] = c[u][v];
                trace[v] = u;
            }
        }
    }

    fto(v, 1, n) {
        int u = trace[v];
        if (u != 0) {
            ke[u].pb(v);
            ke[v].pb(u);
        }
    }

    fto(u, 1, n) {
        f[u] = 0;
        memset(avail, true, sizeof avail);
        DFS(u);
        fto(v, 1, n) {
            if (c[u][v] != f[v]) {
                puts("NO");
                return 0;
            }
//            printf("%d ", f[v]);
        }
//        puts("");
    }

    puts("YES");

    return 0;
}