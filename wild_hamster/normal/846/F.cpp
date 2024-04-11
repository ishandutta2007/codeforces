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
vector<ll> g[1005000];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    ll ans = n*(n+1)*(n+2)/3-n;
    for (i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        g[x].push_back(i+1);
    }
    for (i = 1; i <= 1000000; i++)
    {
        for (j = 0; j+1 < g[i].size(); j++)
        {
            ll x = g[i][j], y = g[i][j+1];
            ans -= x*(n-y+1)*2;
        }
    }
    ll to_div = n*n;
    printf("%.10f\n", (double)((long double)ans/to_div));
    return 0;
}