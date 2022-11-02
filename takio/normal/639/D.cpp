#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<62)-1;
ll t[200005],pre[200005];
ll tk[5][200005];
priority_queue<ll>q;
int main()
{
    int n,k,b,c;
    scanf("%d%d%d%d",&n,&k,&b,&c);
    b=min(b,5*c);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&t[i]);
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++)
            tk[((t[i]+j)%5+5)%5][i]=t[i]+j;
    ll res=INF;
    for(int i=0;i<5;i++)
    {
        while(!q.empty())q.pop();
        ll now=0,offset=0;
        for(int j=1;j<=k;j++)
        {
            now+=c*(tk[i][j]-t[j])+b*(tk[i][k]-tk[i][j])/5;
            q.push(c*(tk[i][j]-t[j])+b*(tk[i][k]-tk[i][j])/5);
        }
        res=min(res,now);
        for(int j=k+1;j<=n;j++)
        {
            now+=k*b*(tk[i][j]-tk[i][j-1])/5;
            offset+=b*(tk[i][j]-tk[i][j-1])/5;
            now+=c*(tk[i][j]-t[j]);
            q.push(c*(tk[i][j]-t[j])-offset);
            now-=q.top()+offset;
            q.pop();
            res=min(res,now);
        }
    }
    printf("%I64d\n",res);
    return 0;
}