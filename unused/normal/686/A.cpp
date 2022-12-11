#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; long long x; int c = 0;
    scanf("%d%lld",&n,&x);
    for (int i = 0; i < n; i++)
    {
        char a; int b;
        scanf(" %c%d",&a,&b);
        if (a == '+') x += b;
        else
        {
            if (x >= b) x -= b; else ++c;
        }
    }
    printf("%lld %d\n", x, c);
}