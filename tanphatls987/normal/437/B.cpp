#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=100000;

int h[maxi]={0},a[maxi],lim,sum,i,ans=0;
int ldgt(int x)
{
    return x&(1+~x);
}
int main()
{
    scanf("%d%d",&sum,&lim);
    for(i=1;i<=lim;i++) a[i]=ldgt(i);
    for(i=lim;i>=1;i--)
    {
        if (a[i]<=sum) {ans++;h[i]=1;sum-=a[i];}
    }
    if (sum) {printf("-1");return 0;}
    printf("%d\n",ans);
    for(i=lim;i>=1;i--) if(h[i]) printf("%d ",i);
}