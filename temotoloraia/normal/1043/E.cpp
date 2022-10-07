#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;
const ll N = 500005;

ll n, m;
ll x[N], y[N], z[N], ans[N];
pair < ll, ll > P[N];
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        scanf ("%lld%lld", &x[i], &y[i]);
    for (int i = 1; i <= n; i++)
        P[i] = {x[i] - y[i], i};
    sort (P + 1, P + n + 1);
    for (int i = 1; i <= n; i++)
        z[P[i].S] = i;
    for (int i = 1; i <= n; i++)
        ans[i] = (z[i] - 1) * y[i] + (n - z[i]) * x[i];
    ll SS = 0;
    for (int i = 1; i <= n; i++){
        ans[P[i].S] += SS;
        SS += x[P[i].S];
    }
    SS = 0;
    for (int i = n; i >= 1; i--){
        ans[P[i].S] += SS;
        SS += y[P[i].S];
    }
    while (m--){
        int u, v;
        scanf ("%d%d", &u, &v);
        if (z[u] > z[v])
            swap (u, v);
        ans[u] -= x[u] + y[v];
        ans[v] -= x[u] + y[v];
    }
    for (int i = 1; i <= n; i++)
        printf ("%lld ", ans[i]);
    cout<<endl;
    return 0;
}