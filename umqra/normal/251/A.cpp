#include <iostream>
using namespace std;

int x[(int)1e5 + 100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    int it = 0;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        while (it != n && x[it] - x[i] <= d)
            it++;                                
        if (x[it - 1]  - x[i] <= d) 
            res += (long long)(it - i - 1) * (long long)(it - i - 2) / 2;
    }                 
    cout << res;

    return 0;
}