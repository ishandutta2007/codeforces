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

int n, w, h, g[maxN], p[maxN], t[maxN];
ii ans[maxN];
map<int, vector<ii> > m[2];

void Solve(map<int, vector<ii> > &m1, map<int, vector<ii> > &m2, bool fromX) {
    forit(it, m1) {
        int p1 = it->ff;
        vector<ii> v = it->ss;
        fto(i, 0, sz(v)-1) {
            int id = v[i].ss;
            int s1 = sz(v)-i-1, s2 = sz(m2[p1]);
//            debug(id);
            bool toX = fromX;
            int x;
            if (s1 < s2) {
                toX = !toX;
                x = m2[p1][s1].ff;
            } else {
                x = v[i+s2].ff;
            }

            if (toX) ans[id] = mp(x, h);
            else ans[id] = mp(w, x);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &w, &h);
    fto(i, 1, n) scanf("%d%d%d", &g[i], &p[i], &t[i]);

    fto(i, 1, n) m[g[i]-1][p[i]-t[i]].pb(mp(p[i], i));
    fto(i, 0, 1) {
        forit(it, m[i]) {
            sort((it->ss).begin(), (it->ss).end());
        }
    }

//    fto(i, 0, 1) {
//        debug(i);
//        forit(it, m[i]) {
//            printf("%d\n", it->ff);
//            for(ii p: it->ss) printf("%d %d\n", p.ff, p.ss);
//        }
//    }

    Solve(m[0], m[1], true);
    Solve(m[1], m[0], false);

    fto(i, 1, n) printf("%d %d\n", ans[i].ff, ans[i].ss);

    return 0;
}