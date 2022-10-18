//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 100005
#define maxM 6
#define oo 1000000007
#define EPS 10e-9

struct segmentTree {
    int t[2*maxN], n;
    void build() {
        for(int i = n-1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
    }
    int query(int l, int r) {
        int res = 0;
        for(l += n-1, r += n; l < r; l>>=1, r>>=1) {
            if (l&1) res = max(res, t[l++]);
            if (r&1) res = max(res, t[--r]);
        }
        return res;
    }
};

int n, m, k, a[maxN][maxM], maxL, ans[6];
segmentTree IT[maxM];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, n)
        fto(j, 1, m) scanf("%d", &a[i][j]);
    fto(j, 1, m) {
        IT[j].n = n;
        fto(i, 1, n) IT[j].t[i+n-1] = a[i][j];
        IT[j].build();
    }

    int l = 1;
    fto(r, 1, n) {
        while (true) {
            int sum = 0;
            fto(j, 1, m) sum += IT[j].query(l, r);
            if (sum <= k) break;
            ++l;
        }
        if (maxL < r-l+1) {
            maxL = r-l+1;
            fto(j, 1, m) ans[j] = IT[j].query(l, r);
        }
    }

    fto(j, 1, m) printf("%d ", ans[j]);

    return 0;
}