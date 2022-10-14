#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
int a[300500], b[300500];
vector<pii> ans;
ll Abs(ll x) {
    return x>0?x:-x;
}
ll dist(ll x1, ll y1, ll x2, ll y2) {
    return Abs(x1-x2) + Abs(y1-y2);
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int minx, miny, maxx, maxy;
    minx = miny = MOD;
    maxx = maxy = -MOD;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[i] = x, b[i] = y;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == minx || a[i] == maxx || b[i] == miny || b[i] == maxy)
            ans.push_back(mp(a[i], b[i]));
    }

    int sz = ans.size();
    int ans1 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < sz; j++)
            for (int k = 0; k < sz; k++)
                ans1 = max(ans1, dist(a[i], b[i], ans[j].X, ans[j].Y) +
                           dist(a[i], b[i], ans[k].X, ans[k].Y) +
                           dist(ans[k].X, ans[k].Y, ans[j].X, ans[j].Y));
    int ans2 = 0;
    for (int i = 0; i < sz; i++)
        for (int j = i; j < sz; j++)
            for (int k = j; k < sz; k++)
    for (int l = k; l < sz; l++) {
        int minx, miny, maxx, maxy;
        minx = miny = MOD;
        maxx = maxy = -MOD;
        vector<pii> hyu;
        hyu.push_back(ans[i]);hyu.push_back(ans[j]);hyu.push_back(ans[k]);hyu.push_back(ans[l]);
        for (int t = 0; t < 4; t++) {
            minx = min(minx, hyu[t].X);
            maxx = max(maxx, hyu[t].X);
            miny = min(miny, hyu[t].Y);
            maxy = max(maxy, hyu[t].Y);
        }
        ans2 = max(ans2, (maxx-minx+maxy-miny)*2);
    }
    cout << ans1 << endl;
    for (int i = 0; i < n-3; i++)
        printf("%d\n", ans2);
    return 0;
}