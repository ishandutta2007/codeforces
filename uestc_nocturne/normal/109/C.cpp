#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
int set[V],nu[V];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    int fa=find(x);
    set[fa]=y;
}
bool check(int x)
{
    while(x>0)
    {
        if(x%10!=4&&x%10!=7)return false;
        x/=10;
    }
    return true;
}
int n,i,x,y,z;
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)set[i]=i;
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(!check(z))
            {
                U(x,y);
            }
        }
        for(i=1;i<=n;i++)nu[i]=0;
        for(i=1;i<=n;i++)nu[find(i)]++;
        LL ans=(LL)n*(LL)(n-1)*(LL)(n-2);
        for(i=1;i<=n;i++)
        {
            if(nu[i]==0||nu[i]==1)continue;
            ans-=(LL)nu[i]*( (LL)(n-nu[i])*(LL)(nu[i]-1)*2 +
                 (LL)(nu[i]-1)*(LL)(nu[i]-2) );
        }
        cout<<ans<<endl;
    }
}