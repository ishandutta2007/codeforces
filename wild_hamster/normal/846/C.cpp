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
#define SQ 2000
#define N 2000000
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,w,h,l,timer;
ll a[100500], pa[100500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        pa[i] = pa[i-1] + a[i];
    }
    ll ans = -(ll)1e+18;
    ll ans1,ans2,ans3;
    for (int i1 = 0; i1 <= n; i1++)
    {
        ll sum = 0, min1 = 0, i2 = i1;
        for (int i3 = i1; i3 <= n; i3++)
        {
            ll tmp = pa[i1] - pa[0] - pa[n] + pa[i3];
            if (ans < tmp+sum-min1*2)
            {
                ans = max(ans, tmp + sum - min1*2);
                ans1 = i1, ans2 = i2, ans3 = i3;
            }
            if (pa[i3+1] - pa[i1] < min1)
                min1 = min(min1, pa[i3+1] - pa[i1]), i2 = i3+1;
            sum += a[i3+1];
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}