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
#define sz(a) (int)a.size()
#define maxN 200005
#define maxK 20
#define oo 1000000000000000007LL
#define MOD 1000000007
#define EPS 1e-9

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

struct edge {int v, c, id, z;};

int n, m, ans[maxN], in[maxN], sum[maxN];
vector<edge> g[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        g[u].pb({v, c, i, 0}); g[v].pb({u, c, i, 1});
        sum[u] += c; sum[v] += c;
        ans[i] = -1;
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        forit(it, g[u]) {
            int v = it->v, c = it->c, id = it->id, z = it->z;
            if (ans[id] == -1) {
                ans[id] = z;
                in[v] += c;
                if (in[v] == sum[v]-in[v] && v != n) q.push(v);
            }
        }
    }

    fto(i, 1, m) printf("%d\n", ans[i]);


    return 0;
}