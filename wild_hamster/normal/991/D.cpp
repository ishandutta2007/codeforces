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
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,tot,x,y,INF, ans;
ll a[1200005], b[1205000], w[1205000], dp[100500][4];
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
string s[2];
int main() {

    //freopen("input.txt","r",stdin);
    cin >> s[0] >> s[1];
    n = s[0].size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++)
            dp[i][j] = -100500;
    }
    dp[0][3] = 0;
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        if (s[0][i] != '0')
            cur += 2;
        if (s[1][i] != '0')
            cur++;
        ll nxt = 0;
        if (i == n-1)
            nxt = 3;
        else {
            if (s[0][i+1] != '0')
                nxt += 2;
            if (s[1][i+1] != '0')
                nxt++;
        }
        if (cur == 0) {
            dp[i+1][3] = max(dp[i+1][3], max(dp[i][2], max(dp[i][1], dp[i][0]))+1);
            dp[i+1][2] = max(dp[i+1][2], dp[i][0]+1);
            dp[i+1][1] = max(dp[i+1][1], dp[i][0]+1);
        }
        if (cur == 1 || cur == 2) {
            dp[i+1][3] = max(dp[i+1][3], dp[i][0]+1);
        }
        dp[i+1][cur] = max(dp[i+1][cur], max(max(dp[i][2], dp[i][3]), max(dp[i][1], dp[i][0])));
    }
    cout << max(max(dp[n][0], dp[n][1]), max(dp[n][2], dp[n][3]));
    return 0;
}