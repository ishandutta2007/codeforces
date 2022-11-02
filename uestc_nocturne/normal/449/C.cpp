/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
struct Edge{int v,ne;}e[V*100];
int p[V],K;
void add(int u,int v)
{
    e[K].v=v;e[K].ne=p[u];p[u]=K++;
}
const int P=1000000007;
bool is[V];
int use[V],cnt[V],n;
int x[V],y[V],ret;
int main()
{
    while(~scanf("%d",&n))
    //for(n=10;n<=30;n++)
    {
        memset(p,-1,sizeof(p));K=0;
        memset(is,0,sizeof(is));
        for(int i=2;i<=n;i++)
        for(int j=2*i;j<=n;j+=i)
        is[j]=1;
        memset(cnt,0,sizeof(cnt));
        for(int i=2;i<=n;i++)
        for(int j=i;j<=n;j+=i)
        add(i,j),cnt[i]++;
        memset(use,0,sizeof(use));
        ret=0;
        for(int i=n;i>=2;i--)
        {
            if(is[i])continue;
            int t=n/i;
            if(t<2)continue;
            int pre=-1;
            for(int j=t;j>2;j--)
            {
                if(use[i*j])continue;
                use[i*j]=1;
                if(pre==-1)pre=i*j;
                else
                {
                    x[ret]=pre;
                    y[ret]=i*j;
                    ret++;
                    use[pre]=1;
                    pre=-1;
                }
            }
            if(pre!=-1)
            {
                use[pre]=1;
                use[i]=1;
                x[ret]=pre;
                y[ret]=i;
                ret++;
            }
            else if(!use[2*i])
            {
                use[2*i]=1;
                use[i]=1;
                x[ret]=2*i;
                y[ret]=i;
                ret++;
            }
        }
        //printf("%d %d\n",n,ret);
        printf("%d\n",ret);
        for(int i=0;i<ret;i++)
        printf("%d %d\n",x[i],y[i]);
    }
}