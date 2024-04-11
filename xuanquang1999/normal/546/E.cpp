//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define forrit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mapii map<int, int>
#define maxN 205
#define oo 1000000007

int n, m, sumA, sumB, sumF, a[maxN], b[maxN], c[maxN][maxN], f[maxN][maxN], traceV[maxN], delta[maxN], source, sink;

bool findPath() {
    fto(u, 1, sink) traceV[u] = 0;
    traceV[source] = source;
    delta[source] = oo;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        fto(v, 1, sink) {
            if (traceV[v] == 0) {
                if (c[u][v] > f[u][v]) {
                    traceV[v] = u;
                    delta[v] = min(delta[u], c[u][v]-f[u][v]);
                    if (v == sink) return true;
                    q.push(v);
                }
                else if (f[v][u] > 0) {
                    traceV[v] = -u;
                    delta[v] = min(delta[u], f[v][u]);
                    if (v == sink) return true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

void incPath() {
    int v = sink;
    while (v != source) {
        int u = traceV[v];
        if (u < 0) {
            u = -u;
            f[v][u]-=delta[sink];
        }
        else f[u][v] += delta[sink];
        v = u;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    source = 2*n+1;
    sink = 2*n+2;
    fto(u, 1, n) {
        scanf("%d", &a[u]);
        sumA+=a[u];
        c[source][u] = a[u];
    }
    fto(u, 1, n) {
        scanf("%d", &b[u]);
        sumB+=b[u];
        c[u+n][sink] = b[u];
    }
    fto(u, 1, n) c[u][u+n] = oo;
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        c[u][v+n] = c[v][u+n] = oo;
    }
//    fto(u, 1, sink) {
//        fto(v, 1, sink) printf("%d ", c[u][v]);
//        printf("\n");
//    }

    while (findPath()) {
        incPath();
//        fto(u, 1, sink) {
//            fto(v, 1, sink) printf("%d ", c[u][v]);
//            printf("\n");
//        }
    }


    fto(u, 1, n) sumF+=f[source][u];

//    debug(sumA);
//    debug(sumB);
//    debug(sumF);

    if (sumA == sumF && sumB == sumF) {
        puts("YES");
        fto(u, 1, n) {
            fto(v, n+1, 2*n) printf("%d ", f[u][v]);
            printf("\n");
        }
    }
    else puts("NO");

    return 0;
}