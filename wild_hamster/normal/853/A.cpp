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
ll a[300500], b[300500];
set<pii> f;
vector<ll> ansv;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i = 0; i < k; i++)
        f.insert(mp(-a[i], i));
    long long ans = 0;
    for (i = k; i < n+k; i++)
    {
        if (i < n)
            f.insert(mp(-a[i], i));
        auto itr = f.begin();
        ans -= 1LL*(i-(*itr).Y)*((*itr).X);
        b[(*itr).Y] = i+1;
        f.erase(itr);
    }
    cout << ans << endl;
    for (i = 0; i < n; i++)
        printf("%d ",b[i]);
    return 0;
}