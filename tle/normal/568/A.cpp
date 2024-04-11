#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define MAXN 3000000
bool ip[3200001];
int ps[3200001],pn=0,rp[3200001],rn=0,a[3200001],b[3200001];
void shai()
{
    bool gg=0;
    for(int i=2;i<=MAXN;i++)
    {
        if(ip[i]) continue;
        ps[++pn]=i;
        if(gg) continue;
        if((long long)i*i>MAXN) {gg=1; continue;}
        for(int j=i*i;j<=MAXN;j+=i) ip[j]=1;
    }
}
int wq(int x)
{
    if(x==0) return 1;
    if(x<10) return 10;
    if(x<100) return 100;
    return 1000;
}
int rv(int x)
{
    if(x==0) return 0;
    if(x<10) return x;
    if(x<100) return x%10*10+x/10;
    return x/10%10*10+x%10*100+x/100;
}
void hw()
{
    for(int i=1;i<=999;i++)
    {
        int cc=i*wq(i)+rv(i);
        if(cc<=MAXN) rp[++rn]=cc;
    }
    for(int i=0;i<=999;i++)
    {
        for(int j=0;j<=9;j++)
        {
            int cc=(i*10+j)*wq(i)+rv(i);
            if(cc>=1&&cc<=MAXN) rp[++rn]=cc;
        }
    }
}
void geta()
{
    int cp=1; a[1]=0;
    for(int i=1;i<=MAXN;i++)
    {
        a[i]=a[i-1];
        if(ps[cp]<=i) ++a[i], ++cp;
    }
}
void getb()
{
    int cp=1; b[1]=0;
    for(int i=1;i<=MAXN;i++)
    {
        b[i]=b[i-1];
        if(rp[cp]<=i) ++b[i], ++cp;
    }
}
int main()
{
    shai(); hw();
    sort(rp+1,rp+1+rn);
    ps[pn+1]=200000000;
    rp[rn+1]=200000000;
    geta(); getb();
    //pi(n)/hw(n)<=p/q
    long long p,q;
    cin>>p>>q;
    int g=-1;
    for(int i=1;i<=MAXN;i++)
    {
        if(q*a[i]<=p*b[i]) g=i;
    }
    printf("%d\n",g);
}