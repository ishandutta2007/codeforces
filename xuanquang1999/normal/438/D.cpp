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

struct Node {
    int m;
    ll sum;
};

struct IT {
private: vector<Node> t; int n;
    void update(int id, int l, int r, int p, int x) {
        if (p > r || p < l) return;
        if (l == p && r == p) {
            t[id].m = x;
            t[id].sum = x;
            return;
        }
        int m = (l+r)/2;
        update(2*id, l, m, p, x); update(2*id+1, m+1, r, p, x);
        t[id].m = max(t[2*id].m, t[2*id+1].m);
        t[id].sum = t[2*id].sum + t[2*id+1].sum;
    }
    ll getSum(int id, int l, int r, int i, int j) {
        if (i > r || j < l) return 0;
        if (i <= l && r <= j) return t[id].sum;
        int m = (l+r)/2;
        return getSum(2*id, l, m, i, j)+getSum(2*id+1, m+1, r, i, j);
    }
    int getL(int id, int l, int r, int i, int j, int x) {
        if (t[id].m < x) return r+1;
        if (l == r) return l;

        int m = (l+r)/2;
        if (i > m) return getL(2*id+1, m+1, r, i, j, x);
        if (j <= m) return getL(2*id, l, m, i, j, x);

        int ans = getL(2*id, l, m, i, j, x);
        if (ans == m+1) ans = getL(2*id+1, m+1, r, i, j, x);
        return ans;
    }
public:
    IT(int n): n(n) {t.assign(4*n+1, {0, 0});}
    void update(int p, int x) {update(1, 1, n, p, x);}
    ll getSum(int l, int r) {return getSum(1, 1, n, l, r);}
    int getL(int l, int r, int x) {return getL(1, 1, n, l, r, x);}
};

int n, q, a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    IT t(n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        t.update(i, a[i]);
    }

    fto(i, 1, q) {
        int type;
        scanf("%d", &type);
        if (type == 3) {
            int k, x;
            scanf("%d%d", &k, &x);
            t.update(k, x);
            a[k] = x;
        } else if (type == 2) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            while (l <= r) {
                int i = t.getL(l, r, x);
                if (i > r) break;
                t.update(i, a[i]%x);
                a[i] %= x;
                l = i+1;
            }
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", t.getSum(l, r));
        }
    }

    return 0;
}