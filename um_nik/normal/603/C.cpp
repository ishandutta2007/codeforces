#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int getG1(int x)
{
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 2;
    return 1 - (x & 1);
}
int getG2(int x)
{
    if (x <= 1) return x;
    if (x <= 4) return x - 2;
    if (x & 1) return 0;
    int z = 0;
    while(x % 2 == 0)
    {
        x /= 2;
        z ^= 1;
    }
    if (x == 1)
        return 2 - z;
    if (x == 3)
        return 1 + z;
    return 2 - z;
}

int main()
{
    int n, k;
    int res = 0;
    scanf("%d%d", &n, &k);
    k &= 1;
    while(n--)
    {
        int x;
        scanf("%d", &x);
        if (k)
            res ^= getG2(x);
        else
            res ^= getG1(x);
    }
    if (res)
        printf("Kevin\n");
    else
        printf("Nicky\n");

    return 0;
}