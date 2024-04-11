//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 100005
#define oo 100000000000007LL
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

bool cmp(const point &a, const point &b) {
    return a.X < b.X;
}

int n, subSize[maxN];
char ans[maxN];
vector<int> tree[maxN], centroidTree[maxN];
bool isCentroid[maxN];

void DFS(int u, int p) {
    subSize[u] = 1;
    forit(it, tree[u]) {
        int v = *it;
        if (v != p && !isCentroid[v]) {
            DFS(v, u);
            subSize[u] += subSize[v];
        }
    }
}

int findCentroid(int u, int p, int root) {
    int heavy = 0;
    forit(it, tree[u]) {
        int v = *it;
        if (v != p && !isCentroid[v] && (heavy == 0 || subSize[v] > subSize[heavy]))
            heavy = v;
    }
    if (subSize[heavy] <= subSize[root]/2 && subSize[root]-subSize[u] <= subSize[root]/2) return u;
    return findCentroid(heavy, u, root);
}

int buildCentroidTree(int u) {
//    debug(u);
    DFS(u, -1);
    int centroid = findCentroid(u, -1, u);
//    fto(v, 1, n) printf("%d ", subSize[v]);
//    puts("");
//    debug(centroid);
    isCentroid[centroid] = true;
    forit(it, tree[centroid]) {
        int v = *it;
        if (!isCentroid[v]) centroidTree[centroid].pb(buildCentroidTree(v));
    }
    return centroid;
}

void DFSCentroid(int u) {
    forit(it, centroidTree[u]) {
        int v = *it;
        ans[v] = ans[u]+1;
        DFSCentroid(v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        tree[u].pb(v); tree[v].pb(u);
    }

    int root = buildCentroidTree(1);
    ans[root] = 'A';
    DFSCentroid(root);

    fto(u, 1, n) printf("%c ", ans[u]);

    return 0;
}