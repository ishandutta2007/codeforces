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
const ll N = 2e5 + 5;

ll n, k, M;
ll a[N];
map < ll, ll > MY;
ll ans;

int main()
{
    cin>>n>>k;
    M = 1;
    while (k--)
        M *= 2;
    n++;
    MY[0] = 1;
    for (ll i = 2; i <= n; i++){
        cin>>a[i];
        a[i] = (a[i] ^ a[i - 1]);
        MY[a[i]]++;
    }
    ans = n * (n - 1) / 2;
    sort (a + 1, a + n + 1);
    for (ll i = 1; i <= n; i++){
            ll nn = MY[a[i]] + MY[M - 1 - a[i]];
            MY[a[i]] = 0;
            MY[M - 1 - a[i]] = 0;
            ll x = nn / 2;
            ll y = nn - x;
            ans -= x * (x - 1) / 2 + y * (y - 1) / 2;
        }
    cout<<ans<<endl;
    return 0;
}