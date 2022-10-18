//84104971101048411497 - Can you guess what does this mean?
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
#define maxN 200005
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

ll mul(ll a, ll b) {
    if (a*b/a != b) return oo;
    return min(oo, a*b);
}

struct UFDS {
    vector<int> pset, rnk;
    UFDS(int n) {
        rnk.assign(n+1, 1);
        pset.resize(n+1);
        fto(u, 1, n) pset[u] = u;
    }
    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }
    bool unionSet(int u, int v) {
        int p = findSet(u), q = findSet(v);
        if (p == q) return false;
        if (rnk[p] < rnk[q]) swap(p, q);
        rnk[p] += rnk[q];
        pset[q] = p;
        return true;
    }
};

int n, m, cnt[maxN];
vector<int> g[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(u, 1, n) {
        g[u].pb(0);
        g[u].pb(n+1);
    }
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    set<int> s;
    fto(u, 1, n+1) s.insert(u);

    UFDS us(n);

    fto(u, 1, n) {
        sort(g[u].begin(), g[u].end());
        fto(i, 0, sz(g[u])-2) {
            int l = g[u][i]+1, r = g[u][i+1]-1;
//            debug(u);
            if (l <= r) {
                us.unionSet(u, l);
//                printf("%d %d\n", l, r);
                while (true) {
                    auto it = s.upper_bound(l);
                    if (*it <= r) {
                        us.unionSet(u, *it);
                        s.erase(it);
                    }
                    else break;
                }
            }
        }
    }

    fto(u, 1, n) {
        int p = us.findSet(u);
        cnt[p] = us.rnk[p];
    }

    vector<int> ans;
    fto(i, 1, n)
        if (cnt[i] > 0) ans.pb(cnt[i]);
    sort(ans.begin(), ans.end());

    printf("%d\n", sz(ans));
    for(int x: ans) printf("%d ", x);

    return 0;
}