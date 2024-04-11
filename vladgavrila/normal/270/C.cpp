#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a, b, lg, mx;
long long x;

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &b, &a);
        lg=0;
        x=1;
        while(x<a)
        {
            x=x*4;
            ++lg;
        }
        mx=max(mx, b+1);
        b+=lg;
        mx=max(mx, b);
    }

    printf("%d\n", mx);

    return 0;
}