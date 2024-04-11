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
#define maxN 300005
#define oo 2000000007
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

int n, m, cnt, deg[maxN];
vector<int> g[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    cnt = m;
    fto(i, 1, n) {
        map<int, vector<int> > s;
        fto(j, 1, m) {
            int x; scanf("%d", &x);
            s[x].pb(j);
        }
        vector<pair<int, vector<int> > > v(s.begin(), s.end());
        fto(x, 0, sz(v)-2) {
            if (v[x].ff != -1) {
                ++cnt;
                for(int j: v[x].ss) g[j].pb(cnt);
                for(int j: v[x+1].ss) g[cnt].pb(j);
            }
        }
    }

    fto(u, 1, cnt) {
        for(int v: g[u]) ++deg[v];
    }

//    fto(u, 1, cnt) {
//        for(int v: g[u]) printf("%d %d\n", u, v);
//    }

    queue<int> q;
    fto(u, 1, cnt) {
        if (deg[u] == 0) q.push(u);
    }

    vector<int> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u <= m) ans.pb(u);
        for(int v: g[u]) {
            --deg[v];
            if (deg[v] == 0) q.push(v);
        }
    }

    if (sz(ans) < m) puts("-1");
    else for(int j: ans) printf("%d ", j);

    return 0;
}