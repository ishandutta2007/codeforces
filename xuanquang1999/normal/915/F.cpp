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
#define maxN 1000005
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

struct Edge {int u, v;};

struct DSU {
private: vector<int> pset, cnt;
public:
    DSU(int n) {
        pset.resize(n+1);
        fto(i, 1, n) pset[i] = i;
        cnt.assign(n+1, 1);
    }
    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }
    bool unionSet(int i, int j) {
        int p = findSet(i), q = findSet(j);
        if (p == q) return false;
        if (cnt[p] < cnt[q]) swap(p, q);
        pset[q] = p;
        cnt[p] += cnt[q];
        return true;
    }
    int getSz(int i) {return cnt[findSet(i)];}
};

int n, a[maxN];
vector<Edge> eMin[maxN], eMax[maxN];

ll SolveMin() {
    DSU s(n);
    ll ans = 0;
    fdto(i, maxN-1, 1) {
        for(Edge e: eMin[i]) {
            ans += 1LL*i*s.getSz(e.u)*s.getSz(e.v);
            s.unionSet(e.u, e.v);
//            printf("%d %d %d %d\n")
        }
    }
//    debug(ans);
    return ans;
}

ll SolveMax() {
    DSU s(n);
    ll ans = 0;
    fto(i, 1, maxN-1) {
        for(Edge e: eMax[i]) {
            ans += 1LL*i*s.getSz(e.u)*s.getSz(e.v);
            s.unionSet(e.u, e.v);
        }
    }
    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        eMin[min(a[u], a[v])].pb({u, v});
        eMax[max(a[u], a[v])].pb({u, v});
    }

    cout << SolveMax() - SolveMin();


    return 0;
}