#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int m,h1,a1,x1,y1,h2,a2,x2,y2;
bool rp[1000001],rp2[1000001];
long long gcd(long long a,long long b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    scanf("%d%d%d%d%d%d%d%d%d",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
    if(h1==a1&&h2==a2)
    {
        cout<<0;
        return 0;
    }
    int ph1=h1,ph2=h2;
    long long hx1=-1,hxt1=-1,hx2=-1,hxt2=-1,ggg;
    for(int p=1;p<=2*m;p++)
    {
        h1=((long long)x1*h1+y1)%m;
    if(h1==a1)
    {
        if(hxt1==-1) hxt1=p; else if(hx1==-1) hx1=p-hxt1;
    }
    }
    for(int p=1;p<=2*m;p++)
    {
        h2=((long long)x2*h2+y2)%m;
    if(h2==a2)
    {
        if(hxt2==-1) hxt2=p; else if(hx2==-1) hx2=p-hxt2;
    }
    }
    if(hxt1==hxt2&&hxt1!=-1) {cout<<hxt1<<"\n"; return 0;}
    if(hxt1!=-1&&hxt2!=-1&&hx2==-1&&(hxt2-hxt1)%hx1==0&&(hxt2-hxt1)/hx1>=0) {cout<<hxt2<<"\n"; return 0;}
    if(hxt1!=-1&&hxt2!=-1&&hx1==-1&&(hxt1-hxt2)%hx2==0&&(hxt1-hxt2)/hx2>=0) {cout<<hxt2<<"\n"; return 0;}
    if(hx1==-1||hx2==-1||hxt1==-1||hxt2==-1)
    {
        cout<<-1;
        return 0;
    }
    //k1*hx1+hxt1=k2*hx2+hxt2
    long long ax=hxt1,bx=hxt2;
    if(ax==bx) {cout<<ax<<"\n"; return 0;}
    for(int i=1;i<=2*m;i++)
    {
        if(ax>bx) bx+=hx2; else ax+=hx1;
        if(ax==bx)
        {
            cout<<ax;
            return 0;
        }
    }
    cout<<-1;
}