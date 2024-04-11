//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 200005
#define maxK 20
#define oo 1000000000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, a[maxN];
ll d[maxN], f1[maxN], f2[maxN], ans = -oo;
vector<int> ke[maxN];

void DFS(int u, int p) {
    d[u] = a[u];
    f1[u] = f2[u] = -oo*2;
    forit(it, ke[u]) {
        int v = *it;
        if (v == p) continue;
        DFS(v, u);
        d[u] += d[v];
        if (f1[v] > f1[u]) {
            f2[u] = f1[u]; f1[u] = f1[v];
        }
        else if (f1[v] > f2[u]) f2[u] = f1[v];
    }
    ans = max(ans, f1[u]+f2[u]);
    f1[u] = max(f1[u], d[u]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    DFS(1, -1);

    if (ans == -oo) puts("Impossible");
    else cout << ans;

    return 0;
}