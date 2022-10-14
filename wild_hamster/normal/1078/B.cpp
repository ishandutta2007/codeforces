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
ll n,m,k,a[100500],x, ls[105][10500] ,b[105], y, z, l, i, j, p;
vector<ll> v;
bool get(int x, int y) {
    return false;
}
bitset<10005> dp[105];
int main() {
     //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
            int x;
        cin >> x;
        b[i] = x;
        if (a[x] == 0)
            p++;
        a[x]++;
    }
    int ans = 1;
    for (int i = 1; i <= 100; i++) {
        if (a[i] > 1) {
            for (int j = 0; j <= n; j++)
                dp[j].reset();
            dp[0][0] = 1;
            for (int j = 0; j < n; j++)
            if (b[j] != i) {
                for (int k = j; k >= 0; k--)
                    dp[k+1] |= (dp[k] << b[j]);
            }
            for (int j = 1; j <= a[i]; j++)
                if (dp[j][j*i] == 1)
                    break;
                else {
                    ans = max(ans, j);
                    if (j == a[i] && p == 2)
                        ans = n;
                }
        }
    }
    cout << ans << endl;
    return 0;
}