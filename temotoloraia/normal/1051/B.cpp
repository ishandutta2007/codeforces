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
const int N = 1e5 + 5;
int main()
{
    ll l, r;
    cin>>l>>r;
    cout<<"YES\n";
    for (ll i = l; i < r; i += 2)
        printf ("%lld %lld\n", i, i + 1);
    return 0;
}