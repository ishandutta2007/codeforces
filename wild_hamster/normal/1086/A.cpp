#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,x,  y, z, l, r, i, j, p[335], q;
ll a[1005][1005], b[300500];
vector<pii> ans, f;
void go(ll x1, ll y1, ll x2, ll y2, ll val) {
    if (val == 0) {
        for (int i = min(x1, x2); i <= max(x1, x2); i++)
            a[i][y1] = 1;
        for (int i = min(y1, y2); i <= max(y1, y2); i++)
            a[x2][i] = 1;
        } else if (val == 1) {
            for (int i = min(x1, x2); i <= max(x1, x2); i++)
            a[i][y2] = 1;
        for (int i = min(y1, y2); i <= max(y1, y2); i++)
            a[x1][i] = 1;
        }
}
int main() {
    cerr << "mesyura hui" << endl;
    //freopen("input.txt","r",stdin);
    ll xa, xb, xc, ya, yb, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
    for (int k = 0; k < 3; k++) {
        ll val = (i==2) + (j==2) + (k==2);
        if (val > 1)
            continue;
        for (int l = 0; l <= 1000; l++)
            for (int r = 0; r <= 1000; r++)
                a[l][r] = 0;
        go(xa, ya, xb, yb, i);
        go(xa, ya, xc, yc, j);
        go(xc, yc, xb, yb, k);
        f.clear();
        for (int l = 0; l <= 1000; l++)
            for (int r = 0; r <= 1000; r++)
        if (a[l][r]) {
            f.push_back(mp(l,r));
        }
        if (ans.empty() || ans.size() > f.size()) {
            ans.clear();
            for (int j = 0; j < f.size(); j++)
                ans.push_back(f[j]);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].X << " " << ans[i].Y << endl;
    return 0;
}