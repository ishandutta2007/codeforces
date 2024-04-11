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
#define maxN 200005
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

struct Node {
    int sum, val;
};

struct IT {
private: vector<Node> t; int n;
    void synthesize(const int &id, const int &l, const int &r) {
        int m = (l+r)/2;
        if (t[id].val) {
            t[2*id].sum = (m-l+1)-t[2*id].sum;
            t[2*id].val ^= 1;
            t[2*id+1].sum = (r-m)-t[2*id+1].sum;
            t[2*id+1].val ^= 1;
            t[id].val = 0;
        }
    }
    void update(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return;
        if (i <= l && r <= j) {
            t[id].sum = (r-l+1)-t[id].sum;
            t[id].val ^= 1;
            return;
        }
        synthesize(id, l, r);
        int m = (l+r)/2;
        update(2*id, l, m, i, j); update(2*id+1, m+1, r, i, j);
        t[id].sum = t[2*id].sum+t[2*id+1].sum;
    }
    int query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (i <= l && r <= j) return t[id].sum;
        synthesize(id, l, r);
        int m = (l+r)/2;
        return query(2*id, l, m, i, j)+query(2*id+1, m+1, r, i, j);
    }
public:
    IT(int n): n(n) {
        t.assign(4*n+1, {0, 0});
    }
    void update(int i, int j) {update(1, 1, n, i, j);}
    int query(int i, int j) {return query(1, 1, n, i, j);}
};

int n, q, dfsCnt, a[maxN], in[maxN], out[maxN];
vector<int> g[maxN];

void DFS(int u) {
    in[u] = ++dfsCnt;
    for(int v: g[u]) {
        DFS(v);
    }
    out[u] = dfsCnt;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(u, 2, n) {
        int p; scanf("%d", &p);
        g[p].pb(u);
    }

    fto(u, 1, n) scanf("%d", &a[u]);
    DFS(1);

    IT t(n);
    fto(u, 1, n) {
        if (a[u]) t.update(in[u], in[u]);
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        char s[5];
        int u;
        scanf("%s%d", s, &u);
        if (s[0] == 'g') {
            printf("%d\n", t.query(in[u], out[u]));
        } else {
            t.update(in[u], out[u]);
        }
    }

    return 0;
}