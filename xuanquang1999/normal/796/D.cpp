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
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define sz(a) (int)a.size()
#define maxN 300005
#define oo 1000000007
#define MOD 1000000007
#define EPS 1e-9
#define double long double

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

int n, k, D;
vector<ii> g[maxN];
bool visited[maxN], police[maxN], used[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &k, &D);
    fto(i, 1, k) {
        int x;
        scanf("%d", &x);
        police[x] = true;
    }

    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(mp(v, i)); g[v].pb(mp(u, i));
    }

    queue<int> q;
    fto(u, 1, n) {
        if (police[u]) {
            q.push(u);
            visited[u] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        forit(it, g[u]) {
            int v = it->ff, id = it->ss;
            if (!visited[v]) {
                visited[v] = true;
                used[id] = true;
                q.push(v);
            }
        }
    }

    vector<int> ans;
    fto(i, 1, n-1) {
        if (!used[i]) ans.pb(i);
    }
    printf("%d\n", sz(ans));
    forit(it, ans) printf("%d ", *it);


    return 0;
}