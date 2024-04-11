#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    long long ans = 1;
    long long k = 0;
    for (long long i = 2; i <= n; i++)  
    {                                
        ans = i + ans + k;
        k = i - 1 + k;
    }
    cout << ans;

    return 0;
}