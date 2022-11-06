#include <cstdio>

using namespace std;

int n, m, x;
int mn, mx, fn, fx;

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        if(i==1)
        {
            mn=mx=x;
        }
        else
        if(x>mx)
        {
            mx=x;
            fx=0;
        }
        else
        if(x<mn)
        {
            mn=x;
            fn=0;
        }

        if(x==mx)
            ++fx;
        if(x==mn)
            ++fn;
    }

    if(mx==mn)
        printf("%d %I64d\n", mx-mn, 1LL*n*(n-1)/2);
    else
        printf("%d %I64d\n", mx-mn, 1LL*fx*fn);

    return 0;
}