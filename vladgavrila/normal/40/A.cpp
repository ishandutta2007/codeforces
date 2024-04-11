#include <stdio.h>

using namespace std;

int n, a, b, i, j, k, tip, dist;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &a, &b);
    if(a*b>=0)
        tip=1;
    dist=a*a+b*b;
    for(int i=1; i<=4000; ++i)
    {
        if(tip==1 && i%2==1 && dist<=i*i && (i-1)*(i-1)<=dist)
        {
            printf("black\n");
            return 0;
        }
        if(tip==0 && i%2==0 && dist<=i*i && (i-1)*(i-1)<=dist)
        {
            printf("black\n");
            return 0;
        }
    }
    printf("white\n");
    return 0;
}