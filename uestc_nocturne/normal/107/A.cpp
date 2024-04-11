#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
const int V=1200;
int n,m,to[V],tof[V],from[V],x[V],y[V],z[V],i,now,te,ct;
int a,b,c;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)
        {
            to[i]=-1;
            tof[i]=0;
            from[i]=-1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            to[a]=b;
            tof[a]=c;
            from[b]=a;
        }
        ct=0;
        for(i=1;i<=n;i++)
        {
            if(to[i]!=-1&&from[i]==-1)
            {
                te=tof[i];
                now=to[i];
                x[ct]=i;
                while(1)
                {
                    if(to[now]==-1)
                    {
                        y[ct]=now;
                        z[ct++]=te;
                        break;
                    }
                    te=min(te,tof[now]);
                    now=to[now];
                }
            }
        }
        printf("%d\n",ct);
        for(i=0;i<ct;i++)
        printf("%d %d %d\n",x[i],y[i],z[i]);
    }
}