#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100000;

int h[maxi],a[maxi],l[maxi],n,i,j,fw,tcons,consume,k;
long long mon;
int compar(const void*x,const void*y)
{
    return a[*(int*)y]-a[*(int*)x];
}
int readfile()
{
    scanf("%d%d",&n,&k);
    cin>>mon;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) l[i]=i+1;
}
int solve()
{
    qsort(l,n,sizeof(int),compar);
    fw=0;consume=0;
    k=min(k-1,n-2);
    for(i=0;i<k;i++)
    {
        if (l[i]==n) fw++;
        consume+=a[l[fw]];
        h[l[fw]]=1;
        fw++;
    }
    //for(i=0;i<n;i++) printf("%d ",l[i]);
    if (l[fw]==n) fw++;
    //printf("%d\n",l[fw]);
    for(i=1;i<n;i++)
    {
        tcons=consume;
        if (h[i]) tcons=tcons-a[i]+a[l[fw]];
        if (mon-tcons<a[i]) {printf("%d",i);return 0;}
    }
    printf("%d",n);
}
int main()
{
    readfile();
    solve();
}