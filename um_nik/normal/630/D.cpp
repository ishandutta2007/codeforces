#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll ans = 1 + 3 * n * (n + 1);
    cout << ans << endl;
    
    return 0;
}