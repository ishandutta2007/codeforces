#include <stdio.h>

using namespace std;

#define maxn 1010
#define maxp 8000000

int n, i, j, k, l, pas;
int f[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    l=0;
    f[l]=1;
    for(int i=1, pas=1; i<=maxp; ++i, ++pas)
    {
        if(pas==n)
            pas=0;
        l=l+pas;
        if(l>=n)
            l-=n;
        f[l]=1;
    }
    for(int i=0; i<n; ++i)
    {
        if(!f[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}