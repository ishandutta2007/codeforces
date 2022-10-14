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
ll n,m,k,x, rt[35], y, z, l, i, j;
ll a[100500], b[100500];
vector<ll> f;
long double pre[155];
long double dp[2][1015][115];
pii tasks[115];
int main() {
    //freopen("input.txt","r",stdin);
    pre[0] = 1;
    long double p = 10./9;
    for (int i = 1; i <= 120; i++)
        pre[i] = pre[i-1] * p;
    ll t;
    cin >> t;
    ll itr = 0;
    while (t--) {
        ll ans = 0;
        cin >> n;
        long double CC, T;
        cin >> CC >> T;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= 1000; j++)
                for (int k = 0; k <= 100; k++)
                    dp[i][j][k] = 1e+18;
        }
        dp[0][0][0] = 0;
        ll cur = 0, nxt = 1;
        for (int i = 0; i < n; i++)
            cin >> tasks[i].X >> tasks[i].Y;
        sort(tasks, tasks + n);
        reverse(tasks, tasks + n);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i * 10 + 10; j++)
                for (int k = 0; k <= i+1; k++)
                    dp[nxt][j][k] = 1e+18;
            for (int j = 0; j <= i * 10; j++) {
                for (int k = 0; k <= i; k++) {
                    long double t = dp[cur][j][k];
                    long double A = 1./CC;
                    long double B = -(T + 1./CC) + 10. * k;
                    long double C = t;
                    long double D = B * B - 4 * A * C;
                    if (D >= 0) {
                        long double x1 = (B + sqrt(D)) / (2. * A);
                        long double x2 = (-B + sqrt(D)) / (2. * A);
                        if (x1 > x2)
                            swap(x1, x2);
                        long double l = max((double)x1, 1.);
                        long double r = min(x2, 1. + T - 10. * k);
                        if (l < r) {
                            if (ans < j) {
                                ans = j;
                                //cout << ans << " " << B << " " << C << " " << x1 << " " << x2 << " " << l << " " << r << endl;
                            }
                        }
                    }
                    if (i == n)
                        continue;
                    dp[nxt][j][k] = min(dp[nxt][j][k], dp[cur][j][k]);
                    dp[nxt][j + tasks[i].Y][k+1] = min(dp[nxt][j+tasks[i].Y][k+1], dp[cur][j][k] + pre[k+1] * tasks[i].X);
                }
            }
            swap(cur, nxt);
        }
        cout << ans << endl;
    }
    return 0;
}