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
#define maxN 100005

int n, m, q;
ll a[maxN], x[maxN], y[maxN], cnt[maxN], d[maxN];
pair<ll, int> l[maxN], r[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &q);
    fto(i, 1, n) scanf("%I64d", &a[i]);
    fto(i, 1, m) {
        ll x1, x2;
        scanf("%I64d%I64d%I64d", &x1, &x2, &d[i]);
        l[i] = mp(x1, i); r[i] = mp(x2, i);
    }
    fto(i, 0, q-1) scanf("%I64d%I64d", &x[i], &y[i]);

    sort(x, x+q); sort(y, y+q);
    int j = 0, k = 0;
    fto(i, 1, maxN-1) {
        while (j < q && x[j] <= i) ++j;
        while (k < q && y[k] < i) ++k;
        cnt[i] = j-k;
    }

//    fto(i, 0, m-1) cout << d[i] << " ";
//    cout << "\n";

    sort(l+1, l+m+1); sort(r, r+m+1);
//    fto(i, 1, m) cout << l[i].fi << " " << l[i].se << endl;
//    cout << "\n";
//    fto(i, 1, m) cout << r[i].fi << " " << r[i].se << endl;
//    cout << "\n";

    j = 1, k = 1; ll cur = 0;
    fto(i, 1, n) {
        while (j <= m && l[j].fi <= i) {
            int x = l[j].se;
            //printf("%I64d ", d[l[j].se]*cnt[l[j].se]);
            cur+=d[x]*cnt[x];
            ++j;
        }
        while (k <= m && r[k].fi < i) {
            int x = r[k].se;
            cur-=d[x]*cnt[x];
            ++k;
        }
        //printf("%I64d\n", cur);
        a[i]+=cur;
    }

    fto(i, 1, n) printf("%I64d ", a[i]);

    return 0;
}