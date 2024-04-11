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
const int INF = 1000*1000*1000;
ll n,m,k,x,y;
ll a[1000500];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    sort(a, a+n);
    ll sum = 0;
    for (int i = n/2; i < n; i++)
        if (a[i] < m)
            sum += m-a[i];
    for (int i = n/2; i >= 0; i--)
        if (a[i] > m)
            sum += a[i]-m;
    cout << sum << endl;

	return 0;
}