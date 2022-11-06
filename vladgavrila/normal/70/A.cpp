#include <stdio.h>

using namespace std;

#define mod 1000003

int n, sol;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    if(n==0)
    {
        printf("1\n");
        return 0;
    }
    sol=1;
    --n;
    while(n--)
        sol=(sol*3)%mod;
    printf("%d\n", sol);
    return 0;
}