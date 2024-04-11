#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    ll n, p;
    cin >> n >> p;
    ll z = n;
    ll t = 9, d = 10;
    ll ans = n;                    
    while (1)
    {
        while (n % d < t && n > 0)
            n -= d / 10;

        if (n + p >= z)
            ans = n;
        else
            break;
        t *= 10;
        d *= 10;
    }
    cout << ans;
    return 0;
}