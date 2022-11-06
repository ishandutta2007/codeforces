#include <stdio.h>
#include <algorithm>

using namespace std;

int n, i, j, k, a, b, c;
long long sol;

int det(int nr)
{
    int up=min(nr/2*2, b*2);
    int down=max(0, (nr-a+1)/2*2);
    return max(0, (up-down)/2+1);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d%d", &n, &a, &b, &c);
    n*=2;
    for(int i=0; i<=c && i*4<=n; ++i)
        sol=sol+det(n-i*4);
    printf("%lld\n", sol);
    return 0;
}