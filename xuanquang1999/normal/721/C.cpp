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
#define maxN 5005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, T, d[maxN][maxN], trace[maxN][maxN];
vector<ii> ke[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &T);
    fto(i, 1, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        ke[u].pb(mp(v, w));
    }
    fto(u, 1, n) {
        fto(l, 1, n) d[u][l] = oo;
    }
    d[1][1] = 0;
    set<pair<int, ii> > s;
    s.insert(mp(0, mp(1, 1)));
    while (!s.empty()) {
        int u = s.begin()->ss.ff, l = s.begin()->ss.ss; s.erase(s.begin());
        forit(it, ke[u]) {
            int v = it->ff, w = it->ss;
            if (d[u][l]+w <= T && d[u][l]+w < d[v][l+1]) {
                s.erase(mp(d[v][l+1], mp(v, l+1)));
                d[v][l+1] = d[u][l]+w;
                s.insert(mp(d[v][l+1], mp(v, l+1)));
                trace[v][l+1] = u;
            }
        }
    }
    int u = n, l = oo;
//    debug(u);
//    debug(l);
    fdto(_l, n, 1) {
        if (d[n][_l] != oo) {
            l = _l;
            break;
        }
    }
//    debug(u);
//    debug(l);
    vector<int> ans;
    while (u != 1) {
        ans.pb(u);
        u = trace[u][l], --l;
    }
    ans.pb(1);

    printf("%d\n", ans.size());
    forrit(rit, ans) printf("%d ", *rit);



    return 0;
}