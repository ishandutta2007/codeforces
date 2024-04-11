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
int set[V];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    int p=find(x);
    if(p==find(y))return;
    set[p]=y;
}
int dg[V],n,m,x,y,nu[V],has[V];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)set[i]=i;
        memset(dg,0,sizeof(dg));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            x--;y--;dg[x]++;dg[y]++;
            U(x,y);
        }
        memset(nu,0,sizeof(nu));
        memset(has,0,sizeof(has));
        int tc=0;
        for(int i=0;i<n;i++)
        {
            if(dg[i]||i==0)nu[find(i)]++,tc++;
            if(dg[i]%2==1)has[find(i)]++;
        }
        int ret=0;
        for(int i=0;i<n;i++)
        {
            if(nu[i]!=0)ret++;
            ret+=max(0,has[i]/2-1);
            if(nu[i]==tc)ret=has[i]/2;
        }
        printf("%d\n",ret);
    }
}