#include <stdio.h>

using namespace std;

int n, m, i, j, k;

int np(int a, int b)
{
    if(a<=0 || b<=0)
        return 0;
    return (b/2+b%2)*(a/2+a%2)+(b/2)*(a/2);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    scanf("%d", &k);
    k--;
    printf("%d\n", np(n-2*k, m-2*k)-np(n-2*(k+1), m-2*(k+1)));
    return 0;
}