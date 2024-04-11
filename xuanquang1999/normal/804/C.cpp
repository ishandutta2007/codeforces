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
#define maxN 300005
#define MOD 1000000007
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

int n, m, ans[maxN];
vector<int> s[maxN], g[maxN];
bool avail[maxN];

void DFS(int u, int p) {
    vector<int> q;
    forit(it, s[u]) {
        if (ans[*it] != 0) avail[ans[*it]] = false;
        else q.pb(*it);
    }
    int c = 1;
//    debug(u);
    forit(it, q) {
        while (!avail[c]) ++c;
        ans[*it] = c;
//        printf("%d %d\n", *it, c);
        ++c;
    }
    forit(it, s[u]) {
        if (ans[*it] != 0) avail[ans[*it]] = true;
    }

    forit(it, g[u]) {
        int v = *it;
        if (v != p) DFS(v, u);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(u, 1, n) {
        int k; scanf("%d", &k);
        s[u].resize(k);
        fto(i, 0, k-1) scanf("%d", &s[u][i]);
    }
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    memset(avail, true, sizeof avail);
    DFS(1, -1);

    fto(i, 1, m) {
        if (ans[i] == 0) ans[i] = 1;
    }

    printf("%d\n", (*max_element(ans+1, ans+m+1)));
    fto(i, 1, m) printf("%d ", ans[i]);

    return 0;
}