#include<bits/stdc++.h>
#define int long long
using namespace std;
 
signed main()
{
    // k = exp / cost;
    int l, r, x, y, k;
    bool ans = 0;
    cin >> l >> r >> x >> y >> k;
    for (int i = x; i <= y; i++)
    {
        if (l <= i * k && i * k <= r)
        {
            ans = 1;
        }
    }
    if (ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}