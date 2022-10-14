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
ll a[505][505], pa[505][505];
pair<ll, pii> queries[250500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m >> k >> q;
    for (i = 0; i < q; i++)
    {
        scanf("%d %d %d", &queries[i].Y.X, &queries[i].Y.Y, &queries[i].X);
    }
    sort(queries, queries+q);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            a[i][j] = 0;
    for (i = 0; i < q; i++)
        a[queries[i].Y.X][queries[i].Y.Y] = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            pa[i][j] = pa[i][j-1] + pa[i-1][j] - pa[i-1][j-1] + a[i][j];
    ll broken = 0;
    for (i = 1; i <= n-k+1; i++)
        for (j = 1; j <= m-k+1; j++)
        {
            ll sum = pa[i+k-1][j+k-1] - pa[i+k-1][j-1] - pa[i-1][j+k-1] + pa[i-1][j-1];
            if (sum == k*k)
                broken = 1;
        }
    if (!broken)
    {
        cout << -1 << endl;
        return 0;
    }
    ll l = 0, r = q-1;
    while (l < r)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                a[i][j] = 0;
        ll mid = (l+r)/2;
        for (i = 0; i <= mid; i++)
            a[queries[i].Y.X][queries[i].Y.Y] = 1;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                pa[i][j] = pa[i][j-1] + pa[i-1][j] - pa[i-1][j-1] + a[i][j];
        ll broken = 0;
        for (i = 1; i <= n-k+1; i++)
            for (j = 1; j <= m-k+1; j++)
                if (pa[i+k-1][j+k-1] - pa[i+k-1][j-1] - pa[i-1][j+k-1] + pa[i-1][j-1] == k*k)
                    broken = 1;
        if (broken)
            r = mid;
        else
            l = mid+1;
    }
    cout << queries[l].X << endl;
    return 0;
}