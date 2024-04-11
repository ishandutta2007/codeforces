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
#define maxN 2005
#define MOD 1000000007

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

int n, d, a[maxN], cnt[maxN], ans;
vector<int> ke[maxN];

void dfs(int u, int par, int root) {
    cnt[u] = 1;
    forit(it, ke[u]) {
        int v = *it;
        if (v == par) continue;
        if (a[v] < a[root] || a[v] > a[root]+d) continue;
        if (a[v] == a[root] && v < root) continue;
        dfs(v, u, root);
        cnt[u] = ((ll)cnt[u]*(cnt[v]+1))%MOD;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &d, &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    fto(u, 1, n) {
        fto(v, 1, n) cnt[v] = 0;
        dfs(u, -1, u);
        ans = (ans+cnt[u])%MOD;
    }

    printf("%d", ans);

    return 0;
}