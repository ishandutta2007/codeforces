//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 100005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

class MinST {
private: vector<int> t;
    void update(int u, int l, int r, int p, int x) {
        if (p < l || p > r) return;
        if (p == l && p == r) {t[u] = x; return;}
        int m = (l+r)/2;
        update(2*u, l, m, p, x); update(2*u+1, m+1, r, p, x);
        t[u] = min(t[2*u], t[2*u+1]);
    }
    int query(int u, int l, int r, int i, int j) {
        if (j < l || i > r) return oo;
        if (i <= l && r <= j) return t[u];
        int m = (l+r)/2;
        return min(query(2*u, l, m, i, j), query(2*u+1, m+1, r, i, j));
    }
public:
    MinST(int n) {t.assign(4*n+1, oo);}
    void update(int p, int x) {update(1, 1, t.size()/4, p, x);}
    int query(int l, int r) {return query(1, 1, t.size()/4, l, r);}
};

class MaxST {
private: vector<int> t;
    void update(int u, int l, int r, int p, int x) {
        if (p < l || p > r) return;
        if (p == l && p == r) {t[u] = x; return;}
        int m = (l+r)/2;
        update(2*u, l, m, p, x); update(2*u+1, m+1, r, p, x);
        t[u] = max(t[2*u], t[2*u+1]);
    }
    int query(int u, int l, int r, int i, int j) {
        if (j < l || i > r) return -oo;
        if (i <= l && r <= j) return t[u];
        int m = (l+r)/2;
        return max(query(2*u, l, m, i, j), query(2*u+1, m+1, r, i, j));
    }
public:
    MaxST(int n) {t.assign(4*n+1, -oo);}
    void update(int p, int x) {update(1, 1, t.size()/4, p, x);}
    int query(int l, int r) {return query(1, 1, t.size()/4, l, r);}
};

int n, s, l, a[maxN], f[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &s, &l);
    MinST minA(n), minF(n+1);
    MaxST maxA(n);
//    minA.update(1, 3);
//    minA.update(2, 2);
//    debug(minA.query(1, 1));
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        minA.update(i, a[i]); maxA.update(i, a[i]);
    }
//    fto(i, 1, n) printf("%d %d %d\n", a[i], minA.query(i, i), maxA.query(i, i));

    f[0] = 0; minF.update(1, 0);
    fto(i, 1, n) f[i] = oo;
    fto(i, l, n) {
//        debug(i);
        int lo = 1, hi = i-l+1, res = maxN;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
//            debug(mid);
//            debug(maxA.query(mid, i));
//            debug(minA.query(mid, i));
            if (maxA.query(mid, i)-minA.query(mid, i) <= s) {
                res = min(res, mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
//        debug(res);
        f[i] = (res > i) ? oo : minF.query(res, i-l+1)+1;
        minF.update(i+1, f[i]);
    }

    printf("%d", (f[n] >= oo) ? -1 : f[n]);

    return 0;
}