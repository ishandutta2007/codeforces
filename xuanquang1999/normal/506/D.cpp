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
#define BASE 343
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

struct DSU {
private:
    vector<int> p;
    vector<int> vertex;
    stack<ii> logP;
public:
    DSU(int n) {
        p.assign(n+1, -1);
    }

    void updateP(int i, int x) {
        logP.push(mp(i, p[i]));
        p[i] = x;
    }

    int findP(int i) {
        if (p[i] < 0) return i;
        int x = findP(p[i]);
        updateP(i, x);
        return x;
    }

    bool makeUnion(int i, int j) {
        vertex.pb(i); vertex.pb(j);
        int x = findP(i), y = findP(j);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        updateP(x, p[x]+p[y]);
        updateP(y, x);
        return true;
    }

    vector<int> getVertex() {
        sort(vertex.begin(), vertex.end());
        vertex.resize(unique(vertex.begin(), vertex.end())-vertex.begin());
        return vertex;
    }

    bool query(int i, int j) {
        return (findP(i) == findP(j));
    }

    void rollBack() {
        while (!logP.empty()) {
            p[logP.top().ff] = logP.top().ss;
            logP.pop();
        }
        vertex.clear();
    }
};

int n, m, q, ans[maxN];
vector<ii> e[maxN];
ii Q[maxN];
unordered_map<int, int> indQ[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        e[c].pb(mp(u, v));
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        scanf("%d%d", &Q[i].ff, &Q[i].ss);
        indQ[Q[i].ff][Q[i].ss] = indQ[Q[i].ss][Q[i].ff] = i;
    }

    DSU s(n);
    fto(c, 1, m) {
        for(ii p: e[c]) {
//            printf("%d %d\n", p.ff, p.ss);
            s.makeUnion(p.ff, p.ss);
        }
        if (sz(e[c]) < BASE) {
            vector<int> vertex = s.getVertex();
//            printf("Vertex:");
//            for(int x: vertex) printf(" %d", x);
//            puts("");
            int k = sz(vertex);
            fto(i, 0, k-2) fto(j, i+1, k-1) {
                int u = vertex[i], v = vertex[j];
                if (indQ[u].count(v)) ans[indQ[u][v]] += s.query(u, v);
            }
        } else {
            fto(i, 1, q) ans[i] += s.query(Q[i].ff, Q[i].ss);
        }
        s.rollBack();
//        fto(i, 1, q) printf("%d ", ans[i]);
//        puts("");
    }

    fto(i, 1, q) {
        ans[i] = ans[indQ[Q[i].ff][Q[i].ss]];
        printf("%d\n", ans[i]);
    }

    return 0;
}