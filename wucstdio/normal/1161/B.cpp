#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1000000009,base=19491001;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,edgenum,head[200005],st[200005],top,d[200005];
ll v[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int hd=head[i];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			st[++top]=(to+n-i)%n;
		}
		sort(st+1,st+top+1);
		for(int j=1;j<=top;j++)v[i]=(v[i]*base+st[j])%MOD;
		v[i]^=d[i];
	}
	for(int d=1;d<n;d++)
	{
		if(n%d)continue;
		bool flag=1;
		for(int i=d+1;i<=n;i++)
		  if(v[i]!=v[i-d])flag=0;
		if(flag)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}