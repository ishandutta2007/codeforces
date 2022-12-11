#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = (int)1e5;

int a[N], b[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
                 
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < n; s++)
        {
            if (i == s)
                continue;
            if (a[i] == b[s])
                cnt++;
        }
    }
    cout << cnt;

    return 0;
}