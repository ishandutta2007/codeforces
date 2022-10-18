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

int n, m, low[maxN], num[maxN], color[maxN], c[maxN], dfsCnt, bcc[maxN], nBcc, ans, cnt, f[maxN];
vector<int> g1[maxN], g2[maxN];
bool bridge[maxN][maxN];

void DFS1(int u, int p) {
    low[u] = num[u] = ++dfsCnt;
    forit(it, g1[u]) {
        int v = *it;
        if (v == p) continue;
        if (!num[v]) {
            DFS1(v, u);
            if (low[v] > num[u]) bridge[u][v] = bridge[v][u] = true;
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
}

void DFS2(int u) {
    ++c[nBcc];
    bcc[u] = nBcc;
    forit(it, g1[u]) {
        int v = *it;
        if (bcc[v] || bridge[u][v]) continue;
        DFS2(v);
    }
}

void DFS3(int u, int p) {
    f[u] = c[u];
    forit(it, g2[u]) {
        int v = *it;
        if (v == p) continue;
        DFS3(v, u);
        f[u] += f[v];
    }
    cnt += c[u]*f[u];
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
        g1[u].pb(v); g1[v].pb(u);
    }

    DFS1(1, -1);
//    fto(u, 1, n) {
//        fto(v, 1, n) printf("%d ", bridge[u][v]);
//        puts("");
//    }

    fto(u, 1, n) {
        if (!bcc[u]) {
            ++nBcc;
            DFS2(u);
        }
    }

    fto(u, 1, n) {
        forit(it, g1[u]) {
            int v = *it;
            if (bcc[u] != bcc[v]) g2[bcc[u]].pb(bcc[v]);
        }
    }

//    fto(u, 1, n) printf("%d ", bcc[u]);
//    puts("");

    fto(u, 1, nBcc) {
        cnt = n*c[u];
        forit(it, g2[u]) {
            int v = *it;
            DFS3(v, u);
        }
        vector<bool> dp(n);
        dp[0] = true;
        forit(it, g2[u]) {
            int v = *it;
            fdto(j, n-c[u], f[v])
                if (dp[j-f[v]]) dp[j] = true;
        }
        fto(j, 0, n)
            if (dp[j]) ans = max(ans, cnt+(n-c[u]-j)*j);
    }

    cout << ans;

    return 0;
}