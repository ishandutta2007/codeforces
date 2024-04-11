#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

typedef long long ll;

#define MOD 1000000007
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define ENDL printf("\n")

using namespace std;

const int maxd=501;

int n,m,b[maxd]={0},a[maxd][maxd],x,y,val,h[maxd],edge[maxd]={0};
double ans,v,e;
int prepare()
{
    //INPUT;
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,1,m)
    {
        scanf("%d%d%d",&x,&y,&val);
        a[x][y]=a[y][x]=val;
    }
}
int check(int r)
{
    do
    {
        //printf("%d ",r);
        v+=b[r];e+=edge[r];
        h[r]=1;
        FOR(i,1,n) if (a[r][i]>0&&h[i]==0) edge[i]+=a[r][i];
        r=0;
        double tmpr=0;
        if (e>0) tmpr=v/e;
        FOR(i,1,n) if (h[i]==0&&edge[i]>0)
        {
            double tmpi=0;
            if (e+edge[i]>0) tmpi=(v+b[i])/(e+edge[i]);
            if (tmpi>tmpr) {tmpr=tmpi;r=i;}
        }
    }while (r);
}
int solve()
{
    ans=0;
    FOR(i,1,n)
    {
        memset(h,0,sizeof(h));
        memset(edge,0,sizeof(edge));
        v=0;e=0;
        check(i);
        if (e>0) ans=max((double(v))/e,ans);
    }
    printf("%.12f",ans);
}
int main()
{
    prepare();
    solve();
}