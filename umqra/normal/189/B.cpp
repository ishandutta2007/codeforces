#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    long long result = 0;
    int w, h;
    cin >> w >> h;
    for ( int i = 0; i <= w; i++ )
    {
        for ( int s = 0; s <= h; s++ )
        {
            long long h1 = min(i, w - i);
            long long w1 = min(s, h - s);
            result += h1 * w1;
        }
    }
    cout << result;
    return 0;
}