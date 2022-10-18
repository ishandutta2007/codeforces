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
#define maxN 200005
#define sz(a) (int)a.size()
#define oo 1000000000000000007LL

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

int n, m, comp[maxN];
vector<int> g[maxN], gt[maxN], order;
bool visited[maxN];
vector<int> a[maxN];

void addEdge(int u, int v) {g[u].pb(v); gt[v].pb(u);}

void DFS(int u) {
    visited[u] = true;
    forit(it, g[u]) {
        int v = *it;
        if (!visited[v]) DFS(v);
    }
    order.pb(u);
}

void DFS(int u, int j) {
    comp[u] = j;
    forit(it, gt[u]) {
        int v = *it;
        if (!comp[v]) DFS(v, j);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        int k; scanf("%d", &k);
        fto(j, 1, k) {
            int x; scanf("%d", &x);
            a[i].pb(x);
        }
    }

    fto(i, 1, n-1) {
        fto(j, 0, sz(a[i])-1) {
            if (j == sz(a[i+1])) {
                puts("No");
                return 0;
            }
            int x = a[i][j], y = a[i+1][j];
            if (x != y) {
                if (x < y) {
//                    printf("%d < %d\n", x, y);
                    addEdge(2*(x-1)+1, 2*(y-1)+1);
                    addEdge(2*(y-1), 2*(x-1));
                } else {
//                    printf("%d > %d\n", x, y);
                    addEdge(2*(x-1)+1, 2*(x-1));
                    addEdge(2*(y-1), 2*(y-1)+1);
                }
                break;
            }
        }
    }

//    fto(i, 0, 2*m-1) {
//        debug(i);
//        for(int v: g[i]) printf("%d ", v);
//        puts("");
//    }

    fto(u, 0, 2*m-1) {
        if (!visited[u]) DFS(u);
    }

    int j = 0;
    forrit(rit, order) {
        int v = *rit;
        if (!comp[v]) DFS(v, ++j);
    }

    fto(i, 0, 2*m-1) {
        if (comp[i] == comp[i^1]) {puts("No"); return 0;}
    }
    puts("Yes");
    vector<int> ans;
    fto(i, 0, m-1) {
        if (comp[2*i] > comp[(2*i)^1]) ans.pb(i+1);
    }
    printf("%d\n", ans.size());
    forit(it, ans) printf("%d ", *it);

    return 0;
}