#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;
const int maxi=100000;
int h[maxi]={0},s[maxi],a[maxi],p[maxi],n,i,j,tmp,top,tmps,l,r,m,ans=0,ansa[5*maxi+1],ansb[5*maxi+1];
int erathostene()
{
    top=0;
    for(i=2;i<=n;i++) if (!h[i])
    {
        for(j=i+i;j<=n;j+=i) h[j]=1;
        top++;
        p[top]=i;
    }
}
int bsearch(int x)
{
    l=1;r=top;
    while(l<=r)
    {
        m=(l+r)/2;
        if (x>=p[m]) l=m+1;
        else r=m-1;
    }
    return p[l-1];
}
int operation(int idx,int des)
{

    while (idx>des)
    {
        tmp=idx;
        idx=idx-bsearch(idx-des+1)+1;

        {
            s[a[tmp]-1]=idx;s[a[idx]-1]=tmp;
            tmps=a[tmp];a[tmp]=a[idx];a[idx]=tmps;
        }
        ans++;
        ansa[ans]=idx+1;ansb[ans]=tmp+1;
    }
}
int main()
{
    scanf("%d",&n);
    erathostene();
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s[a[i]-1]=i;
    }
    for(i=0;i<n;i++) operation(s[i],i);
    printf("%d\n",ans);
    for(i=1;i<=ans;i++) printf("%d %d\n",ansa[i],ansb[i]);
}