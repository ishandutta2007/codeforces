#include <stdio.h>

using namespace std;

#define maxn 1010

int n, i, j, k, ne;
int v[maxn], x[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
        scanf("%d", &x[i]);
    for(int i=n; i; --i)
    {
        ne=0;
        for(int j=1; j<=n-i+1; ++j)
        {
            if(ne==x[i])
            {
                for(int l=n; l>j; --l)
                    v[l]=v[l-1];
                v[j]=i;
                break;
            }
            if(v[j]>=i+k)
                ++ne;
        }
    }
    for(int i=1; i<=n; ++i)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}