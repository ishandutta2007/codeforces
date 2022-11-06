#include <stdio.h>

using namespace std;

long long n, m, a, x;
long long sol;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%I64d%I64d%I64d", &n, &m, &a);
    sol=n/a;
    if(n%a) ++sol;
    x=m/a;
    if(m%a) ++x;
    sol=sol*x;
    printf("%I64d\n", sol);
    return 0;
}