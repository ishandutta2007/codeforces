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
#define maxN 105
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int a[maxN], p[maxN], q[maxN], s, t, n, m, ans;
int c[maxN][maxN], f[maxN][maxN], trace[maxN], delta[maxN];
map<int, bool> used[maxN];

bool FindPath() {
    queue<int> q;
    memset(trace, 0, sizeof trace);
    q.push(s);
    trace[s] = s;
    delta[s] = oo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        fto(v, 1, t) {
            if (trace[v] == 0) {
                if (c[u][v]-f[u][v] > 0) {
                    trace[v] = u;
                    delta[v] = min(delta[u], c[u][v]-f[u][v]);
                    q.push(v);
                    if (v == t) return true;
                }
                else if (f[v][u] > 0) {
                    trace[v] = -u;
                    delta[v] = min(delta[u], f[v][u]);
                    q.push(v);
                    if (v == t) return true;
                }
            }
        }
    }
    return false;
}

void IncFlow() {
    int v = t;
    while (v != s) {
        int u = trace[v];
        if (u < 0) {
            u = -u;
            f[v][u] -= delta[t];
        }
        else f[u][v] += delta[t];
        v = u;
    }
}

void Flow(int x) {
    s = 1; t = n+2;
    int e[maxN];
    memset(e, 0, sizeof e);
    fto(i, 1, n) {
        while (a[i]%x == 0) {
            a[i]/=x;
            ++e[i];
        }
    }
    memset(c, 0, sizeof c);
    //1: source
    //2, 4, 6, ..., n: odd
    //3, 5, 7, ..., n+1: even
    //n+2: sink
    fto(i, 1, m) {
        c[p[i]+1][q[i]+1] = min(e[p[i]], e[q[i]]);
    }
    fto(i, 1, (n+1)/2) c[s][i*2] = e[i*2-1];
    fto(i, 1, n/2) c[i*2+1][t] = e[i*2];
//    fto(i, 1, n) printf("%d ", e[i]);
//    puts("");
//    fto(i, 1, t) {
//        fto(j, 1, t) printf("%d ", c[i][j]);
//        puts("");
//    }
    memset(f, 0, sizeof f);
//    debug(x);
    while (FindPath()) {
        IncFlow();
//        fto(i, 1, t) {
//            fto(j, 1, t) printf("%d ", f[i][j]);
//            puts("");
//        }
    }

    fto(i, 1, m) {
        ans += f[p[i]+1][q[i]+1];
    }
//    debug(ans);
//    puts("");
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, m) {
        scanf("%d%d", &p[i], &q[i]);
        if (p[i]%2 == 0) swap(p[i], q[i]);
    }

    fto(i, 1, n) {
        fto(j, 2, (int)sqrt(a[i])) {
            if (a[i]%j == 0) Flow(j);
        }
        if (a[i] > 1) Flow(a[i]);
    }

    cout << ans;


    return 0;
}