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
#define oo 2000000007

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

int n, m, k;
vector<int> node, ans[maxN], ke[maxN];
bool visited[maxN];

void DFS(int u) {
    if (visited[u]) return;
    visited[u] = true;
    node.pb(u);
    forit(it, ke[u]) {
        int v = *it;
        if (!visited[v]) {
            DFS(v);
            node.pb(u);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    DFS(1);
//    forit(it, node) printf("%d ", *it);
//    puts("");
    fto(i, 1, k) {
        while (!node.empty()) {
            if (ans[i].size() == (2*n+k-1)/k) break;
            ans[i].pb(*node.rbegin());
            node.pop_back();
        }
        if (ans[i].size() == 0) ans[i].pb(1);
    }

    fto(i, 1, k) {
        printf("%d", ans[i].size());
        forit(it, ans[i]) printf(" %d", *it);
        puts("");
    }

    return 0;
}