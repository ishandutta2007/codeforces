using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 20005
#define maxR 1005
#define maxQ 100005

int n, q, ans[maxN], cnt;
vector<pair<ii, int> > p;

int pow2(int x) {
    return (x*x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        int x, r;
        scanf("%d%d", &x, &r);
        p.pb(mp(mp(x, r), i));
        ans[i] = -1;
    }

    sort(p.begin(), p.end());

    scanf("%d", &q);
    fto(i, 1, q) {
        int x, y;
        scanf("%d%d", &x, &y);
        int k = lower_bound(p.begin(), p.end(), mp(mp(x, maxR), maxN))-p.begin(); --k;
        //printf("%d\n", k);
        if (k == n) k = 0;
        if (k >= 0 && ans[p[k].se] == -1 && pow2(x-p[k].fi.fi)+pow2(y) <= pow2(p[k].fi.se)) {
            ++cnt; ans[p[k].se] = i;
        }
        if (k+1 < n && ans[p[k+1].se] == -1 && pow2(x-p[k+1].fi.fi)+pow2(y) <= pow2(p[k+1].fi.se)) {
            ++cnt; ans[p[k+1].se] = i;
        }
    }

    printf("%d\n", cnt);
    fto(i, 0, n-1) printf("%d ", ans[i]);

    return 0;
}