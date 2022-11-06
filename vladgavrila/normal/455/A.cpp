#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, m, x;
long long d[maxn];
int f[maxn];

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        ++f[x];
    }

    d[0]=0;
    d[1]=f[1];

    for(int i=2; i<maxn; ++i)
    {
        d[i]=max(d[i-1], d[i-2]+1LL*f[i]*i);
    }

    printf("%I64d\n", d[maxn-1]);

    return 0;
}