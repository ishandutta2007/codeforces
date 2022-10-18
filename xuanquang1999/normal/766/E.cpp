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
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN], x[maxN];
ll f1[maxN][2], f2[maxN][2], cnt[maxN][2];
vector<int> ke[maxN];

void DFS(int u, int p) {
    cnt[u][x[u]] = 1; cnt[u][1^x[u]] = 0;
    fto(i, 0, 1) f1[u][i] = 0, f2[u][i] = 0;
    forit(it, ke[u]) {
        int v = *it;
        if (v == p) continue;
        DFS(v, u);
        fto(i, 0, 1) cnt[u][i^x[u]] += cnt[v][i];
        fto(i, 0, 1)
            fto(j, 0, 1) f2[u][i^j^x[u]] += f1[u][i]*cnt[v][j];
        fto(i, 0, 1) f1[u][i] += cnt[v][i];
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(u, 1, n) scanf("%d", &a[u]);
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    ll ans = 0;
    fto(j, 0, 19) {
        fto(u, 1, n) x[u] = (a[u]>>j)&1;
        DFS(1, -1);
        fto(u, 1, n) ans += (1<<j)*(f2[u][1]+cnt[u][1]);
    }

    cout << ans;

    return 0;
}