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
#define X real()
#define Y imag()
#define maxN 200005
#define oo 2000000007
#define EPS 1e-9
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


int n, x, da[maxN], db[maxN];
vector<int> g[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &x);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    queue<int> q;

    q.push(1);
    da[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        forit(it, g[u]) {
            int v = *it;
            if (!da[v]) {
                da[v] = da[u]+1;
                q.push(v);
            }
        }
    }

    q.push(x);
    db[x] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        forit(it, g[u]) {
            int v = *it;
            if (!db[v] && db[u]+1 < da[v]) {
                db[v] = db[u]+1;
                q.push(v);
            }
        }
    }

    int ans = 0;
    fto(u, 1, n) {
        if (db[u]) ans = max(ans, (da[u]-1)*2);
    }

    printf("%d", ans);


    return 0;
}