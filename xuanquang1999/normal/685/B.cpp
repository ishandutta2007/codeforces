//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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
#define maxK 30
#define maxN 300005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, k, q, d[maxN], f[maxN], maxF[maxN], leaf[maxN], p[maxN], b[maxK][maxN];
vector<int> ke[maxN];

void DFS(int u) {
    f[u] = 1;
    leaf[u] = u;
    forit(it, ke[u]) {
        int v = *it;
        d[v] = d[u]+1;
        DFS(v);
        f[u] += f[v];
        if (f[v] > maxF[u]) {
            maxF[u] = f[v];
            leaf[u] = leaf[v];
        }
    }
}

bool centroid(int u, int v) {
    return (maxF[v] <= f[u]/2 && f[u]-f[v] <= f[u]/2);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 2, n) {
        scanf("%d", &p[i]);
        ke[p[i]].pb(i);
    }
    p[1] = -1;

    k = (int)log2(n-1);
    fto(u, 1, n) b[0][u] = p[u];
    fto(i, 1, k) {
        fto(u, 1, n) {
            if (b[i-1][u] != -1) b[i][u] = b[i-1][b[i-1][u]];
            else b[i][u] = -1;
        }
    }

//    fto(i, 0, k) {
//        fto(u, 1, n) printf("%d ", b[i][u]);
//        puts("");
//    }


    DFS(1);
//    fto(u, 1, n) printf("%d ", leaf[u]);
//    puts("");
    fto(i, 1, q) {
        int u;
        scanf("%d", &u);
        int v = leaf[u];
        int t = d[v]-d[u];
        //printf("%d %d\n", u, v);
//        if (n == 200000 && q == 200000 && u == 1) {
//            printf("%d\n", t);
//            fto(i, 0, (int)log2(t)) printf("%d ", b[i][v]);
//            puts("");
//        }
        fdto(i, (int)log2(t), 0) {
            if (b[i][v] != -1 && f[b[i][v]] < (f[u]+1)/2) {
                v = b[i][v];
                //if (n == 200000 && q == 200000 && u == 1) printf("%d ", v);
            }
        }
//        if (n == 200000 && q == 200000 && u == 1) puts("");
        if (u != v) v = b[0][v];
//        if (n == 200000 && q == 200000 && v == 0) {
//            printf("%d\n", leaf[u]);
//            printf("%d\n", u);
//        }
        //debug(v);
        //while (!centroid(u, v)) v = b[0][v];
//        if (n != 200000 || q != 200000) printf("%d\n", v);
        printf("%d\n", v);
    }



    return 0;
}