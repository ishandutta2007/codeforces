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
#define maxK 105
#define MOD 1000
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

int n, m, k, s, a[maxN], d[maxK][maxN];
vector<int> g[maxN];
bool visited[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &n, &m, &k, &s);
    fto(u, 1, n) scanf("%d", &a[u]);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    fto(i, 1, k) {
        memset(visited, false, sizeof visited);
        queue<int> q;
        fto(u, 1, n) {
            if (a[u] == i) {
                q.push(u);
                visited[u] = true;
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for(int v: g[u]) {
                if (!visited[v]) {
                    d[i][v] = d[i][u]+1;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    fto(u, 1, n) {
        vector<int> allD(k);
        fto(i, 1, k) allD[i-1] = d[i][u];
        sort(allD.begin(), allD.end());

        int ans = 0;
        fto(i, 0, s-1) ans += allD[i];
        printf("%d ", ans);
    }

    return 0;
}