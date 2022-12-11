#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100000;

int n,i,j,h[maxi],a[maxi];
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    int fail=0;
    for(i=1;i<=3010;i++)
    {
        for(j=1;j<=n;j++) if (i>a[j])
        {
            if (j==1||j==n) fail=1;else if (i>a[j-1]) fail=1;
        }
        if (fail) break;
    }
    printf("%d",i-1);
}