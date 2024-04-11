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
const ll N = 3e5 + 7;
ll n, m;
ll a[N];
int main()
{
    cin>>n>>m;
    for (ll i = 1; i <= n; i++)
        cin>>a[i];
    sort (a + 1, a + n + 1);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans += a[i];
    ans -= a[n];
    ll t = 1;
    for (ll i = 1; i <= n; i++)
        if (a[i] < t)
            ans--;
        else
            t++;
    cout<<ans<<endl;
    return 0;
}