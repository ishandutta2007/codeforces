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

struct segment {
    int l, r, id;
    inline bool operator < (const segment &b) const {
        return (r-l < b.r-b.l);
    }
};

struct segmentTree {
    int T[4*maxN], n;
    void build(int _n) {
        n = _n;
        memset(T, 0, sizeof T);
    }
    void update(int p, int x) {
        for(T[p+=n-1] = x; p > 1; p >>= 1) T[p>>1] = T[p]+T[p^1];
    }
    int query(int l, int r) {
        int res = 0;
        for(l += n-1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += T[l++];
            if (r&1) res += T[--r];
        }
        return res;
    }
};

int n, k, ans[maxN];
segment a[maxN];
set<int> s;
map<int, int> id;
segmentTree Tl, Tr;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;
        s.insert(a[i].l); s.insert(a[i].r);
    }
    forit(it, s) id[*it] = ++k;

    sort(a+1, a+n+1);

    Tl.build(k);
    Tr.build(k);
    fto(i, 1, n) {
        int l = id[a[i].l], r = id[a[i].r];
        ans[a[i].id] = i-(Tl.query(1, l-1)+Tr.query(r+1, k)+1);
        Tl.update(l, 1); Tr.update(r, 1);
    }

    fto(i, 1, n) printf("%d ", ans[i]);

    return 0;
}