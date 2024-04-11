#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
char buf[1000000],*p1,*p2;
inline int rd()
{
	register int x=0;register char c=nc();
	while(c<48)c=nc();
	while(c>47)x=((x+(x<<2))<<1)+(c^48),c=nc();
	return x;
}
int d[N],n,a[N],p[N],vis[N],b[N],cnt;
vector<int>v[N];
int main()
{
	// freopen("data_structs.in","r",stdin);
	// freopen("data_structs.out","w",stdout);
	// int T;scanf("%d",&T);
	// int T=rd();
	for(int i=2;i<=300000;i++)
	{
		if(!p[i])
		{
			p[i]=i;
			for(int j=i;j<=300000;j+=i)if(!p[j])p[j]=i;
		}
	}
	// while(T--)
	// {
		n=rd();p[1]=1;
		// for(int i=0;i<N;i++)v[i].clear();memset(d,0,sizeof(d));memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)b[i]=rd();sort(b+1,b+n+1);cnt=0;
		for(int i=1;i<=n;i++)if(!vis[b[i]])
		{
			a[++cnt]=b[i];
			for(int j=b[i];j<N;j+=b[i])vis[j]=1;
		}
		n=cnt;
		for(int i=1,x,tmp;i<=n;i++)
		{
			// a[i]=rd();
			d[a[i]]++;x=a[i];
			while(x!=1)
			{
				v[i].push_back(p[x]);tmp=p[x];
				while(x%tmp==0)x/=tmp;
			}
		}
		for(int i=1;i<=300000;i++)
			for(int j=i+i;j<=300000;j+=i)
				d[i]+=d[j];
		int ans=n+1;
		for(int i=1;i<=n;i++)
		{
			int sz=v[i].size();
			vector<int>cnt(1<<sz,0),f(1<<sz);
			for(int S=0;S<(1<<sz);S++)
			{
				int x=1;
				for(int j=0;j<sz;j++)if(S&(1<<j))x*=v[i][j];
				cnt[S]=d[x];
			}
			for(int j=0;j<sz;j++)
				for(int S=0;S<(1<<sz);S++)if(S&(1<<j))
					cnt[S^(1<<j)]-=cnt[S];
			for(int j=0;j<sz;j++)
				for(int S=0;S<(1<<sz);S++)if(S&(1<<j))
					cnt[S]+=cnt[S^(1<<j)];
			f[0]=1;
			for(int S=1;S<(1<<sz);S++)
			{
				f[S]=n+1;
				for(int s=S;s;s=S&(s-1))if(cnt[((1<<sz)-1)^s])f[S]=min(f[S],f[S^s]+1);
			}
			ans=min(ans,f[(1<<sz)-1]);
		}
		printf("%d\n",ans==n+1?-1:ans);
	// }
		// 
}