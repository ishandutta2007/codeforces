#include <iostream>
#include <cstdio>
using namespace std;

const int N = (int)1e6;

int a[N];
int up[N], down[N];

int main()
{

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        up[i] = down[i] = i;
        
    int maxV = 0;
    for (int i = n - 1; i > 0; i--)
    {                                           
        if (a[i] >= a[i - 1])
            maxV = max(i, maxV);
        up[i] = max(maxV, i);
        if (a[i] < a[i - 1])
            maxV = 0;         
    }                    

    up[0] = maxV;

    int minV = n;            

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= a[i + 1])
            minV = min(minV, i);
        down[i] = min(minV, i);
        if (a[i] < a[i + 1])
            minV = n;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        int t = up[l];
        int x = down[r];              
        if ((t >= x || x <= l || t >= r))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}