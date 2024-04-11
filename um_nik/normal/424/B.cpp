#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int s;

struct Town
{
    int r, val;

    Town() {}
    Town (int r, int val) : r(r), val(val) {}

    bool operator < (Town A)
    {
        return r < A.r;
    }
};

Town a[1010];

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[i] = Town(x * x + y * y, z);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        s += a[i].val;
        if (s >= 1000000)
        {
            printf("%.10lf\n", sqrt((double)a[i].r));
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}