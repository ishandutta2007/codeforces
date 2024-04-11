#include <bits/stdc++.h>

using namespace std;

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

const int MAXN = 2e5 + 5;
int n, a[MAXN], par[MAXN];
vector<int> g[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    fto(i, 1, n) scanf("%d", &a[i]);

    if (a[1] != 1) {
        puts("No");
        return 0;
    }

    queue<ii> q;
    int root = a[1];
    q.push({root, sz(g[root])});

    par[root] = -1;
    for(int u: g[root])
        if (par[u] == 0) par[u] = root;

    fto(i, 2, n) {
        int u = a[i];
//        printf("%d %d %d\n", i, u, q.front().first);
        if (par[u] != q.front().first) {
            puts("No");
            return 0;
        }

        for(int v: g[u]) {
            if (par[v] == 0) {
                par[v] = u;
            }
        }

        if (q.front().second == 1) q.pop();
        else --q.front().second;

        if (sz(g[u]) > 1) {
//            printf("%d %d\n", u, v);
            q.push({u, sz(g[u])-1});
        }
    }

    puts("Yes");

    return 0;
}