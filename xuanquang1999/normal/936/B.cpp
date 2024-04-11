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
#define maxN 100005
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

int n, m, s, par[maxN][2], dfsCnt, state[maxN];
vector<int> g[maxN];

void answer(string res) {
    cout << res;
    exit(0);
}

void BFS() {
    fto(u, 1, n) fto(p, 0, 1) par[u][p] = -1;
    par[s][0] = 0;
    queue<ii> q;
    q.push(mp(s, 0));

    while (!q.empty()) {
        int u = q.front().ff, p = q.front().ss; q.pop();
        if (sz(g[u]) == 0 && p == 1) {
            puts("Win");
            vector<int> ans;
            while (u != 0) {
                ans.pb(u);
                u = par[u][p]; p ^= 1;
            }
            reverse(ans.begin(), ans.end());
            for(int v: ans) printf("%d ", v);
            exit(0);
        }
        for(int v: g[u]) {
            if (par[v][p^1] == -1) {
                par[v][p^1] = u;
                q.push(mp(v, p^1));
            }
        }
    }
}

void DFS(int u) {
    state[u] = 1;
    for(int v: g[u]) {
        if (state[v] == 1) answer("Draw");
        else if (state[v] == 0) DFS(v);
    }
    state[u] = 2;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(u, 1, n) {
        int k; scanf("%d", &k);
        fto(j, 1, k) {
            int v; scanf("%d", &v);
            g[u].pb(v);
        }
    }
    scanf("%d", &s);

    BFS();
    DFS(s);
    answer("Lose");

    return 0;
}