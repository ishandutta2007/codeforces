#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,m,cnt,q,tot=0;
int w[Maxn],que[Maxn];
bool vis[Maxn+7];
int prime[Maxn+7],nxt[Maxn];
void getprime()
{
    cnt=0;
    memset(vis,false,sizeof(vis));
    for (int i=2;i<=Maxn;i++)
    {
        if (!vis[i]) prime[++cnt]=i;
        for (int j=1;j<=cnt&&1LL*i*prime[j]<=Maxn;j++)
        {
            vis[1LL*i*prime[j]]=true;
            if (i%prime[j]==0) break;
        }
    }
}
int phi(int x)
{
    int res=x,now=x;
    for (int i=1;i<=cnt;i++)
    {
        if (x%prime[i]==0) res-=res/prime[i];
        while (now%prime[i]==0) now/=prime[i];
        if (prime[i]>x) break;
    }
    if (now!=1) res-=res/now;
    return res;
}
int power1(int a,int b,int modp)
{
    int res=1,now=a,left=b;
    while (left>0)
    {
        if (left%2==1) res=(1LL*res*now)%modp;
        left/=2;
        now=(1LL*now*now)%modp;
    }
    return res%modp;
}
long long power(long long a,long long b)
{
    long long res=1,now=a,left=b;
    while (left>0)
    {
        if (left%2==1) res=(1LL*res*now);
        left/=2;
        now=(1LL*now*now);
    }
    return res;
}
bool cp(int lx,int rx,int m)
{
	if (lx==rx) return (w[lx]<=m);
	if (w[lx]>m) return false;
	int t=0;
	long long now=1;
	while (w[lx]<=m/now)
	{
		++t;
		m/=w[lx];
	}
	return cp(lx+1,rx,t);
}
int calc(int lx,int rx,int pos)
{
	int m=que[pos];
	if (lx==rx) return w[lx]%m;
    if (min(nxt[lx+1],rx)-lx<7)
    {
		int now=min(nxt[lx+1],rx);
		if (cp(lx+1,now,que[pos+1]))
		{
			long long res=w[now];
			for (int i=now-1;i>lx;i--)
				res=power(w[i],res);
			res=power1(w[lx],res,m);
			return res%m;
		}
    }
    if (m==0||lx==rx) return w[lx]%m;
    if (m==1) return 0;
    int p=que[pos+1];
    int now=calc(lx+1,rx,pos+1);
    return power1(w[lx],(now%p+p),m);
}
int main()
{
	getprime();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	que[++tot]=m;
	while (m>1)
	{
		m=phi(m);
		que[++tot]=m;
	}
	memset(nxt,0,sizeof(nxt));
	nxt[n+1]=n+1;
	nxt[n]=n+1;
	if (w[n]==1) nxt[n]=1;
	for (int i=n;i;i--)
	{
		nxt[i]=nxt[i+1];
		if (w[i]==1) nxt[i]=i;
	}
	scanf("%d",&q);
	while (q--)
	{
		int lx,rx;
		scanf("%d%d",&lx,&rx);
		printf("%d\n",calc(lx,rx,1));
	}
	return 0;
}