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
#define maxN 500005
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

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a%b);
}

struct IT {
private:
    vector<int> t; int n;
    void update(int id, int l, int r, const int &p, const int &x) {
        if (p < l || p > r) return;
        if (l == p && r == p) {
            t[id] = x;
//            printf("%d %d %d\n", l, r, t[id]);
            return;
        }
        int m = (l+r)/2;
        update(2*id, l, m, p, x); update(2*id+1, m+1, r, p, x);
        t[id] = GCD(t[2*id], t[2*id+1]);
//        printf("%d %d %d\n", l, r, t[id]);
    }
    int getL(int id, int l, int r, const int &i, const int &j, const int &x) {
        if (t[id]%x == 0) return r+1;
        if (l == r) return l;

        int m = (l+r)/2;
        if (i > m) return getL(2*id+1, m+1, r, i, j, x);
        if (j <= m) return getL(2*id, l, m, i, j, x);
        int ans = getL(2*id, l, m, i, j, x);

        if (ans == m+1) ans = getL(2*id+1, m+1, r, i, j, x);
        return ans;
    }
    int getR(int id, int l, int r, const int &i, const int &j, const int &x) {
        if (t[id]%x == 0) return l-1;
        if (l == r) return r;

        int m = (l+r)/2;
        if (i > m) return getR(2*id+1, m+1, r, i, j, x);
        if (j <= m) return getR(2*id, l, m, i, j, x);
        int ans = getR(2*id+1, m+1, r, i, j, x);

        if (ans == m) ans = getR(2*id, l, m, i, j, x);
        return ans;
    }
public:
    IT(int n): n(n) {t.assign(4*n+1, 1);}
    void update(int p, int x) {update(1, 1, n, p, x);}
    int getL(int i, int j, int x) {return getL(1, 1, n, i, j, x);}
    int getR(int i, int j, int x) {return getR(1, 1, n, i, j, x);}
};

int n, q, a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    IT t(n);
    fto(i, 1, n) t.update(i, a[i]);

    scanf("%d", &q);
    fto(i, 1, q) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            int lo = t.getL(l, r, x)-1, hi = t.getR(l, r, x)+1;
//            printf("%d %d\n", lo, hi);
            puts((lo >= hi-2) ? "YES" : "NO");
        } else {
            int p, x; scanf("%d%d", &p, &x);
            t.update(p, x);
        }
    }


    return 0;
}