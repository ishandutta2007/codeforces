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
ll n,m,k,y, x, t, z, tot;
string s;
ll a[10005000], p[25], sz;
int main()
{
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    p[0] = 1;
    for (int i = 1; i <= 18; i++)
        p[i] = p[i-1]*10;
    for (int i = 0; i < 19; i++)
        for (int j =i+1; j < 19; j++)
            for (int k = j+1; k < 19; k++)
                for (int l = 1; l <= 9; l++)
                    for (int r = 1; r <= 9; r++)
                        for (int t = 1; t <= 9; t++)
                            a[sz++] = p[i]*l+p[j]*r+p[k]*t;

    for (int i = 0; i < 19; i++)
        for (int j =i+1; j < 19; j++)
                for (int l = 1; l <= 9; l++)
                    for (int r = 1; r <= 9; r++)
                            a[sz++] = p[i]*l+p[j]*r;
    for (int i = 0; i < 19; i++)
                for (int l = 1; l <= 9; l++)
                            a[sz++] = p[i]*l;
    sort(a, a+sz);

    while (n--) {
        ll l,r;
        cin >> l >> r;
        ll ans = upper_bound(a, a+sz, r) - upper_bound(a, a+sz, l-1);
        cout << ans << endl;
    }
	return 0;
}