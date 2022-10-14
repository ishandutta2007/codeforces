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
typedef int ll;
using namespace std;
ll n,m,k,y, x, t, z, tot;
string s;
ll dp[3205050][5], b[5], d[15][15], to_add[15][15], h[5], period;
ll sz[5][5];
vector<ll> g[5][5];
int main()
{
    //freopen("input.txt", "r", stdin);
    //cin >> s;
    //cout << s.find("hyu") << endl;
    /*vector<ll> f;
    for (int i = 0; i < 7; i++)
        f.push_back(1<<i);
    brute(f);
    cout << g.size() << endl;*/
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        if (x > z)
            swap(x, z);
        if (x == z) {
            b[x] += y;
            continue;
        }
        g[x][z].push_back(y);
    }
    ll max_val = 1;
    for (int i = 1; i <= 3; i++)
        for (int j = i+1; j <= 4; j++) {
            sort(g[i][j].begin(), g[i][j].end());
            reverse(g[i][j].begin(), g[i][j].end());
            sz[i][j] = g[i][j].size() + 1;
            to_add[i][j] = max_val;
            if (i == 3)
                period = max_val + 15;
            max_val *= sz[i][j];
        }
    ll ans = 0;
    for (int i = 1; i <= 4; i++)
        ans = max(ans, b[i]);
    for (int i = 1; i <= 3200000; i++)
        for (int j = 1; j <= 4; j++)
            dp[i][j] = -MOD;
    for (int i = 0; i < max_val; i++) {
        ll tmp_sz = 0;
        ll cur_val = i;
        for (int k = 1; k <= 3; k++)
            for (int j = k+1; j <= 4; j++) {
                d[k][j] = cur_val % sz[k][j];
                cur_val /= sz[k][j];
                //cout << i << " " << k << " " << j << " " << d[k][j] << endl;
            }
        for (int j = 1; j <= 4; j++)
            h[j] = 0;
        for (int j = 1; j <= 4; j++) {
            ll cur_dp = dp[i%period][j];
            for (int k = 1; k <= 4; k++) {
                if (j == k)
                    continue;
                ll x = j, y = k;
                if (x > y)
                    swap(x, y);
                ll idx = (i+to_add[x][y])%period;
                if (d[x][y]) {
                    //cout << i << " " << x << " " << y << endl;
                    h[x] = h[y] = 1;
                }
                if (d[x][y]+1 == sz[x][y])
                    continue;

                dp[idx][k] = max(dp[idx][k], cur_dp + g[x][y][d[x][y]]);
            }
        }
        ll mag = 0;
        for (int j = 1; j <= 4; j++)
            mag += h[j] * b[j];
        //mag = 0;
        for (int j = 1; j <= 4; j++) {
            ans = max(ans, dp[i%period][j]+mag);
            dp[i%period][j] = -MOD;
        }
    }
    cout << ans << endl;
	return 0;
}