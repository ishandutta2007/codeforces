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
#define oo 1000000007
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

struct BIT {
    vector<int> t;
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i)) t[i] += x;
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
    int query(int l, int r) {
        return query(r)-query(l-1);
    }
};

int n, q, p[maxN], l[maxN], ans[maxN], a[maxN];
vector<ii> Q[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d", &p[i], &l[i]);
    scanf("%d", &q);
    fto(i, 1, q) {
        int l, r; scanf("%d%d", &l, &r);
        Q[l].pb(mp(r, i));
    }

    BIT t(n);
    vector<int> s;

    fdto(i, n, 1) {
        if (i < n) t.update(i+1, p[i+1]-p[i]);

        int k;
        while ((k = sz(s)) && p[i]+l[i] >= p[s[k-1]]) {
            t.update(s[k-1], -t.query(s[k-1], s[k-1]));
            s.pop_back();
        }
        if (k > 0) {
            int x = p[s[k-1]] - (p[i]+l[i]);
            t.update(s[k-1], min(0, x-t.query(s[k-1], s[k-1])));
        }
        s.pb(i);

        for(ii p: Q[i])
            ans[p.ss] = t.query(p.ff);

//        fto(i, 1, n) printf("%d ", t.query(i, i));
//        puts("");
    }

    fto(i, 1, q) printf("%d\n", ans[i]);

    return 0;
}