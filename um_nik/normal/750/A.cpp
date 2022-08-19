#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    k = 240 - k;
    k /= 5;
    int ans = 0;
    while(ans < n && k >= ans + 1)
    {
        ans++;
        k -= ans;
    }
    cout << ans << endl;


    return 0;
}