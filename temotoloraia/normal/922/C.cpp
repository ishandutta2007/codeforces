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
ll n, k;
set < ll >S;
int main()
{
    cin>>n>>k;
    if (k > 10000){cout<<"No\n";return 0;}
    for (ll i = 1; i <= k; i++)
        S.insert (n%i);
    if (S.size() < k)
        cout<<"No\n";
    else
        cout<<"Yes\n";
    return 0;
}