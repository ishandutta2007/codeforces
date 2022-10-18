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
#define maxN 100005
#define oo 3000000000000000000LL

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

int n, d[maxN], init[maxN], goal[maxN];
vector<int> ke[maxN], ans;

void DFS(int u, int p, int c[2]) {
    int C[2] = {c[0], c[1]};
    int val = init[u]^goal[u]^C[d[u]&1];
    if (val) {
        ans.pb(u);
        C[d[u]&1] ^= 1;
    }

//    printf("%d %d %d %d %d %d %d %d\n", u, p, init[u], goal[u], d[u], C[0], C[1], val);
    forit(it, ke[u]) {
        int v = *it;
        if (v == p) continue;
        d[v] = d[u]+1;
        DFS(v, u, C);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }
    fto(i, 1, n) scanf("%d", &init[i]);
    fto(i, 1, n) scanf("%d", &goal[i]);
//    fto(i, 1, n) printf("%d %d\n", init[i], goal[i]);
    d[1] = 1;
    int c[2] = {0, 0};
    DFS(1, -1, c);

    printf("%d\n", ans.size());
    forit(it, ans) printf("%d\n", *it);

    return 0;
}