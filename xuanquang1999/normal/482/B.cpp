#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl;
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, l, r) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define oo 1000000007
#define maxN 100005

//struct query {
//    int l, r, q;
//    inline bool operator < (const query &b) {
//        return ((l < b.r) || (l == b.r && r < b.r));
//    }
//};

int n, k, cnt[30], t[2*maxN], lq[maxN], rq[maxN], xq[maxN];
ii l[maxN], r[maxN];

void build () {
    fdto(i, 1, n-1) t[i] = t[i<<1]&t[i<<1|1];
}

int query (int l, int r) {
    int res = (1<<30)-1;
    for(l += n-1, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = res&t[l++];
        if (r&1) res = res&t[--r];
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    fto(i, 1, k) {
        scanf("%d%d%d", &lq[i], &rq[i], &xq[i]);
        l[i] = mp(lq[i], xq[i]), r[i] = mp(rq[i], xq[i]);
    }

    sort(l+1, l+k+1);
    sort(r+1, r+k+1);

    int il = 1, ir = 1;
    fto(i, 1, n) {
        while (il <= k && l[il].ff <= i) {
            fto(b, 0, 29) {
                if ((l[il].ss>>b)&1) ++cnt[b];
            }
            ++il;
        }
        while (ir <= k && r[ir].ff < i) {
            fto(b, 0, 29) {
                if ((r[ir].ss>>b)&1) --cnt[b];
            }
            ++ir;
        }
        fto(b, 0, 29) {
            if (cnt[b] > 0) t[i+n-1] |= 1<<b;
        }
    }

    build();
    fto(i, 1, k) {
        if (query(lq[i], rq[i]) != xq[i]) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    fto(i, n, 2*n-1) printf("%d ", t[i]);

    return 0;
}