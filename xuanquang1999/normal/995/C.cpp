#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef complex<double> point;
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
#define maxN 100005
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, x[maxN], y[maxN], id[maxN], ans[maxN];
vector<ii> g[maxN];

std::mt19937 rng(time(NULL));

int random(int l, int r) {
    std::uniform_int_distribution<int> gen(l, r); // uniform, unbiased
    return gen(rng);
}

ll sq(int x, int y) {
    return 1LL*x*x + 1LL*y*y;
}

void DFS(int u) {
    for(ii p: g[u]) {
        int v = p.ff, w = p.ss;
        ans[v] = ans[u]*w;
        DFS(v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d", &x[i], &y[i]);
    fto(i, 1, n) id[i] = i;

    srand(time(NULL));

    ordered_set X;
    fto(i, 1, n) X.insert(i);

    ll lim = 1000000000000;
    int save = n;
    while (n > 1) {
        int i = random(0, n-1), j = random(0, n-1);
        if (i == j) continue;
        i = *X.find_by_order(i); j = *X.find_by_order(j);
//        printf("%d %d\n", i, j);
        if (n == 2) lim = 1500000LL*1500000LL;
        if (sq(x[i]+x[j], y[i]+y[j]) <= lim) {
            g[id[i]].pb(mp(id[j], 1));
            x[i] += x[j];
            y[i] += y[j];
        } else if (sq(x[i]-x[j], y[i]-y[j]) <= lim) {
            g[id[i]].pb(mp(id[j], -1));
            x[i] -= x[j];
            y[i] -= y[j];
        } else continue;

        X.erase(j);
        id[j] = -1;
        --n;
    }

    int root = *X.find_by_order(0);
    ans[root] = 1;
    DFS(root);

    fto(u, 1, save) printf("%d ", ans[u]);

    return 0;
}