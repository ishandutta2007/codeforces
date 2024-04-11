//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <time.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define fos (feof(stdin))
typedef long double ld;
typedef long long ll;
void swap(int& a,int& b) {a^=b; b^=a; a^=b;}
void swap(ll& a,ll& b) {a^=b; b^=a; a^=b;}
void swap(bool& a,bool& b) {if(a!=b) {a^=1; b^=1;}}
template <class T>
T* fnew(int siz) //TPOD 
{
    T* p=(T*)malloc(sizeof(T)*siz);
    memset(p,0,sizeof(T)*siz);
    return p;
}
//
int n,hn=0,sn=0;
struct hl {int x,y1,y2;}hs[666666];
struct sl {int y,x1,x2;}ss[666666],ss2[666666];
int yn=0,yy[666666];
void LS(int& x)
{
    x=lower_bound(yy+1,yy+1+yn,x)-yy;
}
bool cmp1(sl x,sl y)
{
    return x.x1<y.x1;
}
bool cmp2(sl x,sl y)
{
    return x.x2<y.x2;
}
bool cmp3(hl x,hl y)
{
    return x.x<y.x;
}
bool sbcmp1(hl a,hl b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.y1<b.y1;
}
bool sbcmp2(sl a,sl b)
{
    if(a.y!=b.y) return a.y<b.y;
    else return a.x1<b.x1;
}
namespace bits
{
    int n; ll b[666666];
    ll gs(int x)
    {
        ll ans=0;
        for(;x>=1;x-=x&-x) ans+=b[x];
        return ans;
    }
    void edit(int x,int y)
    {
        for(;x<=n;x+=x&-x) b[x]+=y;
    }
}
namespace jjj
{
    int hn=0,sn=0;
hl hs[666666];
sl ss[666666],ss2[666666];
void ah(int x,int y1,int y2)
{
    ++hn; hs[hn].x=x; hs[hn].y1=y1; hs[hn].y2=y2;
}
void sh(int y,int x1,int x2)
{
    ++sn; ss[sn].y=y; ss[sn].x1=x1; ss[sn].x2=x2;
}
ll j2()
{
    long long cur=0;
    for(int i=1;i<=hn;i++) LS(hs[i].y1),LS(hs[i].y2);
    for(int i=1;i<=sn;i++) LS(ss[i].y);
    for(int i=1;i<=sn;i++) ss2[i]=ss[i];
    sort(hs+1,hs+1+hn,cmp3);
    sort(ss+1,ss+1+sn,cmp1);
    sort(ss2+1,ss2+1+sn,cmp2);
    int csd=1,csd2=1;
    for(int i=1;i<=hn;i++)
    {
        int x=hs[i].x,y1=hs[i].y1,y2=hs[i].y2;
        while(csd<=sn&&ss[csd].x1<=x)
        {
            bits::edit(ss[csd].y,1);
            ++csd;
        }
        while(csd2<=sn&&ss2[csd2].x2<x)
        {
            bits::edit(ss2[csd2].y,-1);
            ++csd2;
        }
        cur-=bits::gs(y2);
        cur+=bits::gs(y1-1);
    }
    return cur;
}
}
ll ghs()
{
    ll A=0;
    for(int i=1;i<=hn;i++)
    {
        int tat;
        for(int j=i;j<=hn&&hs[j].x==hs[i].x;j++) tat=j;
        ll cans=0;
        int cx=hs[i].y1,cy=hs[i].y2;
        for(int j=i+1;j<=tat;j++)
        {
            if(cy<hs[j].y1)
            {
                jjj::ah(hs[i].x,cx,cy);
                cans+=(ll)cy-cx+1; cx=hs[j].y1; cy=hs[j].y2;
            }
            else cy=max(cy,hs[j].y2);
        }
        jjj::ah(hs[i].x,cx,cy);
        cans+=(ll)cy-cx+1;
        i=tat; A+=cans;
    }
    return A;
}
ll gss()
{
    ll A=0;
    for(int i=1;i<=sn;i++)
    {
        int tat;
        for(int j=i;j<=sn&&ss[j].y==ss[i].y;j++) tat=j;
        ll cans=0;
        int cx=ss[i].x1,cy=ss[i].x2;
        for(int j=i+1;j<=tat;j++)
        {
            if(cy<ss[j].x1)
            {
                jjj::sh(ss[i].y,cx,cy);
                cans+=(ll)cy-cx+1; cx=ss[j].x1; cy=ss[j].x2;
            }
            else cy=max(cy,ss[j].x2);
        }
        jjj::sh(ss[i].y,cx,cy);
        cans+=(ll)cy-cx+1;
        i=tat; A+=cans;
    }
    return A;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(y1>y2) swap(y1,y2);
        if(x1>x2) swap(x1,x2);
        if(x1==x2)
        {
            ++hn; hs[hn].x=x1; hs[hn].y1=y1; hs[hn].y2=y2;
            yy[++yn]=y1; yy[++yn]=y2;
        }
        else
        {
            ++sn; ss[sn].y=y1; ss[sn].x1=x1; ss[sn].x2=x2;
            yy[++yn]=y1;
        }
    }
    sort(hs+1,hs+1+hn,sbcmp1);
    sort(ss+1,ss+1+sn,sbcmp2);
    bits::n=yn+3;
    ll cur=ghs()+gss();
    sort(yy+1,yy+1+yn);
    cur+=jjj::j2();
    cout<<cur<<"\n";
    return 0;
}