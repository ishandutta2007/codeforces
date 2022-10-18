//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct segmentTree {
    int n, a, t[2*maxN];
    void build(int _a, int _n) {
        n = _n;
        a = _a;
    }
    void update(int p, int x) {
        for(t[p += n-1] = min(t[p]+x, a); p > 1; p >>= 1) {
            t[p>>1] = t[p]+t[p^1];
        }
    }
    int query(int l, int r) {
        int res = 0;
        for(l += n-1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }
    void print() {
        fto(i, 1, 2*n-1) printf("%d ", t[i]);
        puts("");
    }
};

segmentTree Ta, Tb;
int n, k, a, b, q;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    Ta.build(a, n);
    Tb.build(b, n);

    fto(i, 1, q) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int d, a;
            scanf("%d%d", &d, &a);
            Ta.update(d, a);
            Tb.update(d, a);
//            Ta.print();
//            Tb.print();
        }
        else if (t == 2) {
            int p;
            scanf("%d", &p);
            printf("%d\n", Tb.query(1, p-1)+Ta.query(p+k, n));
        }
    }

    return 0;
}