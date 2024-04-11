//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define maxK 20
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

struct point {ll x, y;};

ll cross(const point &A, const point &B) {
    return A.x*B.y - A.y*B.x;
}

bool CCW(const point &A, const point &B, const point &C) {
    return cross({B.x-A.x, B.y-A.y}, {C.x-A.x, C.y-A.y}) > 0;
}

int n, q, k, b[maxK][maxN], d[maxN];
point p[maxN];

int LCA(int u, int v)  {
    if (d[u] < d[v]) swap(u, v);
    int t = d[u]-d[v];
    fto(i, 0, k) {
        if ((t>>i)&1) u = b[i][u];
    }

    fdto(i, k, 0) {
        if (b[i][u] != b[i][v]) {
            u = b[i][u];
            v = b[i][v];
        }
    }
    if (u == v) return u;
    fto(i, 0, k) {
        if (b[i][u] == b[i][v]) return b[i][u];
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) cin >> p[i].x >> p[i].y;

//    debug(CCW(p[4], p[5], p[6]));

    vector<int> s;
    s.pb(n);
    fdto(i, n-1, 1) {
        while (sz(s) > 1 && CCW(p[i], p[s[sz(s)-1]], p[s[sz(s)-2]])) s.pop_back();
        b[0][i] = s[sz(s)-1];
        d[i] = d[s[sz(s)-1]]+1;
        s.pb(i);
    }

//    fto(i, 1, n) printf("%d ", b[0][i]);
//    puts("");

    k = log2(n);
    fto(i, 1, k) {
        fto(u, 1, n) b[i][u] = b[i-1][b[i-1][u]];
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d ", LCA(u, v));
    }

    return 0;
}