#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll dp[55][2], a[55];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        k += a[i];
    }
    dp[n-1][0] = a[n-1];
    dp[n-1][1] = 0;
    for (i = n-1; i >= 1; i--)
    {
        dp[i-1][0] = max(a[i-1] + dp[i][1], dp[i][0]);
        dp[i-1][1] = min(a[i-1] + dp[i][1], dp[i][0]);
    }
    cout << k-dp[0][0] << " " << dp[0][0] << endl;
    return 0;
}