#include <stdio.h>

using namespace std;

#define maxn 110

int n, m, k, a, b;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=k; ++i)
    {
        scanf("%d%d", &a, &b);
        if(a<=5 || b<=5 || (n-a)<=4 || (m-b)<=4)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}