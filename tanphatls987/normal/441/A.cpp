#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100;

int n,h[maxi],tmp,k,v,a[maxi]={0},i,ans=0;
int main()
{
    scanf("%d%d",&n,&v);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        while(k)
        {
            scanf("%d",&tmp);
            if ((tmp<a[i])||(!a[i])) a[i]=tmp;
            k--;
        }
        if (a[i]<v) {h[i]=1;ans++;}else h[i]=0;
    }
    printf("%d\n",ans);
    for(i=1;i<=n;i++) if (h[i]) printf("%d ",i);
}