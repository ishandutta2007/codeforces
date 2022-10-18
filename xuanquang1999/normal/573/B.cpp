using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
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

int n, h[maxN], d[maxN], ans;
ii a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &h[i]);
        a[i] = mp(h[i], i);
    }
    sort(a+1, a+1+n);

//    fto(i, 1, n) printf("%d %d\n", a[i].fi, a[i].se);

    queue<int> q;
    q.push(1), d[1] = 1;
    q.push(n), d[n] = 1;
    int k = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans = max(ans, d[u]);
//        debug(u);
//        debug(ans);
//        debug(k);
        while (k <= n && a[k].fi <= ans) {
//            debug(a[k].se);
//            debug(d[a[k].se]);
            if (!d[a[k].se]) {
                d[a[k].se] = ans;
                q.push(a[k].se);
//                debug(a[k].se);
            }
            ++k;
        }
        fto(j, -1, 1)
            if (j != 0) {
                int v = u+j;
                if (v < 1 || v > n) continue;
                if (!d[v]) {
                    d[v] = d[u]+1;
                    q.push(v);
                }
            }
    }

    printf("%d", ans);

    return 0;
}