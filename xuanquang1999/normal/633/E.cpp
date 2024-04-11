//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1000005
#define oo 1000000007
#define double long double

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct minSegmentTree {
    int t[2*maxN], n;
    void build(int a[], int k) {
        n = k;
        fto(i, n, 2*n-1) t[i] = a[i-n+1];
        fdto(i, n-1, 1) t[i] = min(t[i<<1], t[i<<1|1]);
    }
    int query(int l, int r) {
        int res = oo;
        for(l += n-1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = min(res, t[l++]);
            if (r&1) res = min(res, t[--r]);
        }
        return res;
    }
};

struct maxSegmentTree {
    int t[2*maxN], n;
    void build(int a[], int k) {
        n = k;
        fto(i, n, 2*n-1) t[i] = a[i-n+1];
        fdto(i, n-1, 1) t[i] = max(t[i<<1], t[i<<1|1]);
    }
    int query(int l, int r) {
        int res = 0;
        for(l += n-1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = max(res, t[l++]);
            if (r&1) res = max(res, t[--r]);
        }
        return res;
    }
};

int n, k, v[maxN], c[maxN], op[maxN];
minSegmentTree ct;
maxSegmentTree vt;

bool cmp(int a, int b) {
    return (a > b);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &v[i]);
    fto(i, 1, n) scanf("%d", &c[i]);
    vt.build(v, n);
    ct.build(c, n);

    double ans = 0;
    fto(x, 1, n) {
        int l = x, r = n, res = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            int pv = 100*vt.query(x, mid), pc = ct.query(x, mid);
            res = max(res, min(pv, pc));
            if (pv <= pc) l = mid+1;
            else r = mid-1;
        }
        op[x] = res;
    }

    sort(op+1, op+n+1, cmp);
    double cur = 1.0*k/n;
    fdto(i, n, k) {
        ans += cur*op[i];
        cur *= 1.0*(i-k)/(i-1);
    }
    cout << setprecision(69) << ans;


    return 0;
}