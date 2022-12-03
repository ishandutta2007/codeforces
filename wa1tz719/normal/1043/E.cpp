#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int x[300005],y[300005];
long long ans[300005];
struct node
{
    int x;
    int id;
    friend bool operator < (const node &a,const node &b)
    {
        if (a.x!=b.x)
        {
            return a.x<b.x;
        }
        else
        {
            return a.id<b.id;
        }
    }
};
node z[300005];
long long sum[300005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    long long tot=0;
    for (i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        ans[i]=(long long)x[i]*(n-2);
        tot+=x[i];
        y[i]-=x[i];
        z[i].id=i;
        z[i].x=y[i];
    }
    sort(z,z+n);
    for (i=0;i<n;i++)
    {
        sum[i+1]=sum[i]+z[i].x;
        ans[i]+=tot;
    }
    for (i=0;i<n;i++)
    {
        ans[z[i].id]+=(long long)z[i].x*(n-i-1)+sum[i];
    }
    for (i=0;i<m;i++)
    {
        int xx,yy;
        scanf("%d%d",&xx,&yy);
        xx--;
        yy--;
        int p=x[xx]+x[yy];
        if (y[xx]<y[yy])
        {
            p=p+y[xx];
        }
        else
        {
            p=p+y[yy];
        }
        ans[xx]-=p;
        ans[yy]-=p;
    }
    for (i=0;i<n;i++)
    {
        printf("%I64d ",ans[i]);
    }
    return 0;
}