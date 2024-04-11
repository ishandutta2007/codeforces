#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
long long a, k;
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &a, &k);
        for (int i = 1; i < k; i++)
        {
            long long t = a;
            int minn = 10, maxx = -1;
            while (t)
            {
                checkmax(maxx, t % 10);
                checkmin(minn, t % 10);
                t /= 10;
            }
            if (!minn)
            {
                break;
            }
            a += minn * maxx;
        }
        printf("%lld\n", a);
    }
    return 0;
}