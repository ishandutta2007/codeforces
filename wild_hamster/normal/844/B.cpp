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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,Q, mx,used[200500], w[200500], W[200500], start;
ll a[55][55];
string s;
set<char> f;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        int x = 0;
        for (j = 0; j < m; j++)
            x += a[i][j];
        ans += (1LL<<x) + (1LL<<m-x) - 2;
    }
    for (i = 0; i < m; i++)
    {
        int x = 0;
        for (j = 0; j < n; j++)
            x += a[j][i];
        ans += (1LL<<x) + (1LL<<n-x) - 2;
    }
    ans -= n*m;
    cout << ans << endl;
    return 0;
}