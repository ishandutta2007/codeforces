#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
ll n, l;
ll a[100005], s[100005];
ll ans = 1e18;
int main()
{
    cin>>n>>l;
    n--;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    a[0] = 1e18 + 1000;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = l; i <= n; i++){
        ll x = s[i] - s[i - l];
        ans = min (x, ans);
    }
    cout<<ans<<endl;
    return 0;
}