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
#define maxN 300005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct segmentTree {
    int T[4*maxN], n;
    void build(int _n) {
        n = _n;

    }
    void update(int p, int x) {
        for(T[p+=n-1] = x; p > 1; p >>= 1) T[p>>1] = min(T[p], T[p^1]);
    }
    int query(int l, int r) {
        int res = oo;
        for(l += n-1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = min(res, T[l++]);
            if (r&1) res = min(res, T[--r]);
        }
        return res;
    }
};

int n, m, a[maxN], p[maxN];
ii b[maxN];
segmentTree T;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        p[a[i]] = i;
    }
    fto(i, 1, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        b[i].ff = p[x], b[i].ss = p[y];
        if (b[i].ff > b[i].ss) swap(b[i].ff, b[i].ss);
    }
    sort(b+1, b+m+1);

    int j = m, minD = n;
    ll ans = 0;
    fdto(i, n, 1) {
        while (j > 0 && b[j].ff >= i) {
            minD = min(minD, b[j].ss-1);
            --j;
        }
        ans += minD-i+1;
    }

    cout << ans;

    return 0;
}