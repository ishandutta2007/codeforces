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

int n, m, col[maxN];
vector<int> ke[maxN], ans1, ans2;

void DFS(int u, int c) {
    col[u] = c;
    if (c == 1) ans1.pb(u);
    else ans2.pb(u);
    forit(it, ke[u]) {
        int v = *it;
        if (!col[v]) DFS(v, 3-c);
        else if (col[v] != 3-c) {
            puts("-1");
            exit(0);
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
        ke[u].pb(v); ke[v].pb(u);
    }
    fto(u, 1, n) {
        if (col[u] == 0) DFS(u, 1);
    }

    printf("%d\n", ans1.size());
    forit(it, ans1) printf("%d ", *it);
    puts("");
    printf("%d\n", ans2.size());
    forit(it, ans2) printf("%d ", *it);
    puts("");

    return 0;
}