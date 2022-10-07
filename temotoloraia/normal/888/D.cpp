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
ll n, k;
ll ans = 1;
int main()
{
    cin>>n>>k;
    for (ll x = 2; x <= k; x++){
        ll pas = 1;
        for (ll i = 1; i <= x; i++)
            pas = pas * (n - i + 1) / i;
        if (x == 3)
            pas *= 2;
        if (x == 4)
            pas *= 9;
        ans += pas;
    }
    cout<<ans<<endl;
    return 0;
}