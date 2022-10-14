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
ll a[2000500], pa[2005000], pb[2005000];
vector<ll> ans;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> x >> y;
    ll diff = x/y;
    for (i = 0; i < n; i++)
    {
        int z;
        scanf("%d",&z);
        a[z]++;
    }
    for (i = 1; i <= N; i++)
    {
        pa[i] = pa[i-1] + a[i];
        pb[i] = pb[i-1] + a[i]*(N-i+1);
    }
    ll min_val = (ll)1e+18;
    for (i = 2; i <= N; i++)
    {
        ll ans = 0;
        for (j = i; j <= N; j+=i)
        {
            if (diff >= i-1)
            {
                ans += (pb[j-1] - pb[j-i] - (pa[j-1]-pa[j-i])*(N-j+1))*y;
            } else
            if (diff == 0)
            {
                ans += (pa[j-1] - pa[j-i])*x;
            } else
            {
                ans += (pb[j-1] - pb[j-diff-1] - (pa[j-1]-pa[j-diff-1])*(N-j+1))*y +
                (pa[j-diff-1]-pa[j-i])*x;
            }
        }
        min_val = min(min_val, ans);
    }
    cout << min_val << endl;
    return 0;
}