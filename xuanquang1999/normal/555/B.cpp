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
#define maxN 200005

int n, m, ans[maxN];
ll a[maxN], li[maxN], ri[maxN];
pair<ll, int> c[maxN];
pair<pair<ll, ll>, int>  b[maxN];
set<pair<ll, int> > s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1) scanf("%I64d%I64d", &li[i], &ri[i]);
    fto(i, 0, n-2) b[i] = mp(mp(li[i+1]-ri[i], ri[i+1]-li[i]), i);
    fto(i, 0, m-1) {
        scanf("%I64d", &a[i]);
        c[i] = mp(a[i], i);
    }

    sort(b, b+n-1);
    sort(c, c+m);

    fto(i, 0, n-2) ans[i] = -1;

    int j = 0;
    fto(i, 0, m-1) {
        while (j < n-1 && b[j].fi.fi <= c[i].fi) {
            s.insert(mp(b[j].fi.se, b[j].se));
            ++j;
        }
        if (!s.empty()) {
            pair<ll, int> top = *s.begin();
            if (c[i].fi <= top.fi) ans[top.se] = c[i].se;
            s.erase(top);
        }
    }

    fto(i, 0, n-2)
        if (ans[i] == -1) {
            printf("No");
            return 0;
        }

    printf("Yes\n");
    fto(i, 0, n-2) printf("%d ", ans[i]+1);

    return 0;
}