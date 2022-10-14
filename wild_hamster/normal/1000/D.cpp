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
#define MOD 998244353
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,tot,y,INF, ans;
ll a[1200005], b[1205000], dp[1205000], rev[1200500], bull[1200500], C[1008][1008];
map<ll, ll> f;
int main() {

    //freopen("input.txt","r",stdin);
    for (int i = 0; i <= 1005; i++)
        C[i][0] = C[i][i] = 1;
    for (int i = 0; i <= 1005; i++)
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            for (int j = i + a[i] + 1; j <= n; j++)
                dp[j] = (dp[j] + dp[i] * C[j-i-1][a[i]]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}