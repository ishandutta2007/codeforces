#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mn=1<<20;
int f[mn*4+2];int n,a[mn];
void blt(int p,int l,int r)
{
    if(l==r-1)
    {
        if(l<n)f[p]=1;else f[p]=0;
        return;
    }
    int mid=(l+r)/2;
    blt(p*2+1,l,mid),blt(p*2+2,mid,r);
    f[p]=f[p*2+1]+f[p*2+2];
}
int ask(int p,int l,int r,int x,int y)
{
    if(l==r-1)
    {
        f[p]=0;a[x]=l;
        return 0;
    }
    int mid=(l+r)/2;
    int c=(x>>y)&1,S=-1;
    if(c==0)
    {
        if(f[p*2+2])S=ask(p*2+2,mid,r,x,y-1)+(1<<y);else
        if(f[p*2+1])S=ask(p*2+1,l,mid,x,y-1);
    }else
    {
        if(f[p*2+1])S=ask(p*2+1,l,mid,x,y-1)+(1<<y);else
        if(f[p*2+2])S=ask(p*2+2,mid,r,x,y-1);
    }
    f[p]=f[p*2+1]+f[p*2+2];
    return S;
}
int main()
{
    scanf("%d",&n);n++;
    blt(0,0,mn);
    ll S=0;
    for(int i=0;i<n;i++)
        S+=ask(0,0,mn,i,19);
    cout<<S<<endl;
    for(int i=0;i<n;i++)
        printf("%d%c",a[i],i==n-1?'\n':' ');
    return 0;
}