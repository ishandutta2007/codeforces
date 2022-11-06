#include <cstdio>
#include <algorithm>

using namespace std;

int n, a, b;
long long s1 = 1LL*(1000000000)*(1000000000);

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int c = 1; 1LL*c*c*c<=n; ++c)
    {
        if(n%c)
            continue;
        for(int i=1; 1LL*i*i<=(n/c); ++i)
        {
            if((n/c)%i>0)
                continue;
            s1=min(s1, 1LL*(c+1)*(i+2)*(n/c/i+2));
        }
    }
    long long s2 = 1LL*(1LL*n+1)*9-1LL*n;

    printf("%I64d %I64d\n", s1-n, s2);
    return 0;
}