#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int N = (int)1e5 + 100;
int a[N], t[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;

    for (int i = 30; i >= 0; i--)
    {                            
        int ind = 0;
        for (int s = 0; s < n; s++)
        {
            if (a[s] & (1 << i))
                t[ind++] = a[s];
        }
        int res = t[0];     
        for (int s = 0; s < ind; s++)
            res &= t[s];     
        if (res != 0 && (res % (1 << i)) == 0)
        {
            printf("%d\n", ind);
            for (int s = 0; s < ind; s++)
                printf("%d ", t[s]);
            return 0;
        }
    }

    throw;

    return 0;
}