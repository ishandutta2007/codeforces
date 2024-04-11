#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int V=1000100;
LL tr[2][V];
int N;
void update(int id,int k,LL v)
{
    if(k==0){printf("Wr : %d %d\n",id,k);return;}
    while(k<=N)
    {
        tr[id][k]+=v;
        k+=k&-k;
    }
}
LL read(int id,int k)
{
    LL ret=0;
    while(k)
    {
        ret+=tr[id][k];
        k-=k&-k;
    }
    return ret;
}
int l[V],r[V],h[V];
double ex[V];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        N=n;
        for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
        h[0]=h[n+1]=-1;
        for(int i=1;i<=n;i++)
        l[i]=r[i]=i;
        for(int i=1;i<=n;i++)
        while(h[l[i]-1]>h[i])l[i]=l[l[i]-1];
        for(int i=n;i>0;i--)
        while(h[r[i]+1]>=h[i])r[i]=r[r[i]+1];
        memset(tr,0,sizeof(tr));
        for(int i=1;i<=n;i++)
        {
            int sr=r[i]-i+1;
            int sl=i-l[i]+1;
            int x=min(sl,sr);
            int y=sl+sr-1;
            int z=y-x+1;
            //printf("%d %d %d %d\n",i,x,y,z);
            update(1,1,h[i]);
            update(1,x+1,-h[i]);
            update(1,y+1,h[i]);
            update(1,z,-h[i]);
            update(0,z,(LL)h[i]*(1+y));
            update(0,y+1,-(LL)h[i]*(1+y));
            update(0,x+1,(LL)h[i]*x);
            update(0,z,-(LL)h[i]*x);
        }
        memset(ex,0,sizeof(ex));
        for(int i=1;i<=n;i++)
        {
            ex[i]+=1.0*read(0,i)/(n-i+1);
            ex[i]+=1.0*read(1,i)/(n-i+1)*i;
        }
        int Q;
        scanf("%d",&Q);
        while(Q--)
        {
            int x;
            scanf("%d",&x);
            printf("%.10f\n",ex[x]);
        }
    }
}