#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100000;
struct candy{int h,v,p;};
candy a[maxi],b[maxi];
int btop=-1,atop=-1,n,x,type,he,val,i;
int compar(const void*x,const void*y)
{
    return ((candy*)x)->v-((candy*)y)->v;
}
int readfile()
{
    //freopen("436a.txt","r",stdin);
    scanf("%d%d",&n,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&type,&he,&val);
        if (type)
        {
            btop++;
            b[btop].h=he;b[btop].v=val;b[btop].p=0;
        }else
        {
            atop++;
            a[atop].h=he;a[atop].v=val;a[atop].p=0;
        }
    }
    if (atop>0)qsort(a,atop+1,sizeof(candy),compar);
    if (btop>0)qsort(b,btop+1,sizeof(candy),compar);
}
int solve()
{
    int ansa=0;int ansb=0;
    int tmpx=x;
    while (1)
    {
        i=atop;
        while (((a[i].h>tmpx)||(a[i].p==1))&&(i>=0)) i--;
        if (i<0) break;
        ansa++;a[i].p=1;
        tmpx+=a[i].v;
        i=btop;
        while (((b[i].h>tmpx)||(b[i].p==1))&&(i>=0)) i--;
        if(i<0) break;
        ansa++;b[i].p=1;
        tmpx+=b[i].v;
    }
    for(i=0;i<=atop;i++) a[i].p=0;
    for(i=0;i<=btop;i++) b[i].p=0;
    tmpx=x;
    while (1)
    {
        i=btop;
        while (((b[i].h>tmpx)||(b[i].p==1))&&(i>=0)) i--;
        if(i<0) break;
        ansb++;b[i].p=1;
        tmpx+=b[i].v;
        i=atop;
        while (((a[i].h>tmpx)||(a[i].p==1))&&(i>=0)) i--;
        if (i<0) break;
        ansb++;a[i].p=1;
        tmpx+=a[i].v;
    }
    //cout<<ansa<<" "<<ansb<<endl;
    cout<<max(ansa,ansb);
}
int main()
{
    readfile();
    solve();
}