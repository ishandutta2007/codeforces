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
using namespace std;
const ll N = 605;
ll n;
ll ans;
int main()
{
    cin>>n;
    for (ll x = 1; x <= n; x++)
    for (ll y = x; y <= n; y++){
        ll z = (x^y);
        if (z >= y && z < x + y && z <= n)
            ans++;
    }
    cout<<ans;
    return 0;
}