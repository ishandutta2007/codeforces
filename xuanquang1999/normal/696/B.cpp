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
#define maxN 100005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, f[maxN], p[maxN];
double ans[maxN];
vector<int> ke[maxN];

void DFS(int u) {
    f[u] = 1;
    forit(it, ke[u]) {
        int v = *it;
        DFS(v);
        f[u] += f[v];
    }
}

void DFS2(int u) {
    forit(it, ke[u]) {
        int v = *it;
        ans[v] = ans[u]+1+(f[u]-1-f[v])/2.0;
        DFS2(v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);

    fto(i, 2, n) {
        scanf("%d", &p[i]);
        ke[p[i]].pb(i);
    }

    ans[1] = 1;
    DFS(1);
    DFS2(1);

    fto(i, 1, n) printf("%.10g ", ans[i]);

    return 0;
}