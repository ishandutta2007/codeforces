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

int n, lastNode;
vector<ii> ke[maxN];
vector<int> ans;

void DFS(int u, int p) {
    forit(it, ke[u]) {
        int v = it->ff, c = it->ss;
        if (v == p) continue;
        if (c == 2) lastNode = v;
        DFS(v, u);
    }
    if (lastNode == u) {
        lastNode = 0;
        ans.pb(u);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        ke[u].pb(mp(v, c)); ke[v].pb(mp(u, c));
    }

    DFS(1, -1);

    printf("%d\n", ans.size());
    forit(it, ans) printf("%d ", *it);

    return 0;
}