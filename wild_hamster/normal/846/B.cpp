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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,w,h,l,timer;
ll a[100500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k >> x;
    for (i = 0; i < k; i++)
    {
        cin >> a[i];
        m += a[i];
    }
    ll ans = 0;
    for (i = 0; i <= n; i++)
    if (x >= m*i)
    {
        ll tmp = (k+1)*i;
        f.clear();
        for (j = 0; j < n-i; j++)
            for (l = 0; l < k; l++)
            {
                f.push_back(a[l]);
            }
        sort(f.begin(), f.end());
        ll val = x-m*i;
        for (j = 0; j < f.size(); j++)
            if (val >= f[j])
                tmp++,val-=f[j];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}