#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=200000;
struct mys{int v;int h;}c[maxi+1];
int compar(const void*x,const void*y)
{
    return ((mys*)x)->v-((mys*)y)->v;
}
int b[maxi+2]={0},a[maxi+2]={0},n,m,i,key,tmp,j;
int64_t ans,suma,sumb,sla,slb;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) {scanf("%d",&tmp);c[i].h=1;c[i].v=tmp;}
    for(i=1;i<=m;i++) {scanf("%d",&tmp);c[n+i].v=tmp;c[n+i].h=0;}
    qsort(c,n+m+1,sizeof(mys),compar);
    for(i=1;i<=n+m;i++) a[i]=a[i-1]+c[i].h;
    for(i=n+m;i>=0;i--) {if(!c[i].h) sumb+=c[i].v;b[i]=b[i+1]+1-c[i].h;}
    sla=0;slb=b[1];
    ans=100000000000000;c[0].v=0;
    //printf("%I64d %I64d\n",suma,sumb);
    for(i=1;i<=n+m;i++)
    {


        suma+=sla*(c[i].v-c[i-1].v);
        sumb-=slb*(c[i].v-c[i-1].v);
        if (c[i].h) sla++;else slb--;
        //printf("%I64d %I64d\n",suma,sumb);
        if (suma+sumb<ans) ans=suma+sumb;
    }
   /* key=0;
    for(i=0;i<=n+m+1;i++) if (abs(a[i]-b[i])<abs(a[key]-b[key])) key=i;
    //while ((a[i+1]==a[key]))
    if ((key>0)&&(key<=n+m)) for(j=1;j<=n+m;j++)
    {
         if ((c[j].v<c[key].v)&&(c[j].h)) ans+=c[key].v-c[j].v;
         if ((c[j].v>c[key].v)&&(!c[j].h)) ans+=c[j].v-c[key].v;
    }*/
    printf("%I64d",ans);
}