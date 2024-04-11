#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
int k,n[16],v[16][5005],res[16][5005],f[1<<15],last[1<<15];
ll out[16],to[16];
ll d[16];
bool flag[16];
map<ll,int>mp;
int main()
{
	scanf("%d",&k);
	ll tot=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&n[i]);
		for(int j=1;j<=n[i];j++)
		{
			scanf("%d",&v[i][j]);
			mp[v[i][j]]=i;
			tot+=v[i][j];
			d[i]+=v[i][j];
		}
	}
	if(tot%k)
	{
		printf("No\n");
		return 0;
	}
	for(int i=1;i<=k;i++)d[i]-=tot/k;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n[i];j++)
		{
			res[i][j]=-1;
			if(d[i]==0)
			{
				res[i][j]=1<<(i-1);
				continue;
			}
			memset(flag,0,sizeof(flag));
			ll val=v[i][j];
			int s=1<<(i-1);
			int p=i;
			val-=d[p];
			p=mp[val];
			if(p==0||p==i)continue;
			while(p!=i)
			{
				s|=1<<(p-1);
				flag[p]=1;
				val-=d[p];
				p=mp[val];
				if(p==0||flag[p])break;
			}
			if(p==i&&val!=v[i][j])p=0;
			if(p!=i)res[i][j]=-1;
			else res[i][j]=s;
		}
	}
	f[0]=1;
	for(int i=0;i<(1<<k)-1;i++)
	{
		if(f[i]==0)continue;
		int node=0;
		while((1<<node)&i)node++;
		node++;
		for(int j=1;j<=n[node];j++)
		{
			if(res[node][j]==-1)continue;
			if(res[node][j]&i)continue;
			f[i|res[node][j]]=1;
			last[i|res[node][j]]=node*10000+j;
		}
	}
	if(f[(1<<k)-1]==0)
	{
		printf("No\n");
		return 0;
	}
	int now=(1<<k)-1;
	while(now!=0)
	{
		int x=last[now]/10000;
		int y=last[now]%10000;
		now^=res[x][y];
		ll val=v[x][y];
		int p=x,last=0;
		out[p]=v[x][y];
		val-=d[p];
		last=p;
		p=mp[val];
		to[p]=last;
		while(p!=x)
		{
			out[p]=val;
			val-=d[p];
			last=p;
			p=mp[val];
			to[p]=last;
		}
	}
	printf("Yes\n");
	for(int i=1;i<=k;i++)printf("%lld %lld\n",out[i],to[i]);
	return 0;
}