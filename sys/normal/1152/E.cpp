#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,a[Maxn],b[Maxn],cur[Maxn],c[Maxn],head[Maxn],tmp[2*Maxn],tot,Cnt,ct,cnt[Maxn],coun;
bool del[2*Maxn];
map <int,int> Ma,rev;
struct edg
{
	int nxt,to;
}edge[2*Maxn];
void add(int x,int y)
{
	edge[++Cnt]=(edg){head[x],y};
	head[x]=Cnt;
}
void dfs(int u)
{
	for(int &i=cur[u];i;i=edge[i].nxt)
	{
		if(del[i]) continue;
		del[i]=del[((i-1)^1)+1]=true;
		int to=edge[i].to;
		dfs(to);
	}
	c[++coun]=u;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<n;i++)
		if(a[i]>b[i])
		{
			printf("-1");
			return 0;
		}
	for(int i=1;i<n;i++)
		tmp[i]=a[i];
	for(int i=1;i<n;i++)
		tmp[i+n-1]=b[i];
	sort(tmp+1,tmp+2*n-1);
	for(int i=1;i<2*n-1;i++)
		if(tmp[i]!=tmp[i-1]) Ma[tmp[i]]=++ct,rev[ct]=tmp[i];
	for(int i=1;i<n;i++)
		a[i]=Ma[a[i]],cnt[a[i]]++;
	for(int i=1;i<n;i++)
		b[i]=Ma[b[i]],cnt[b[i]]++;
	for(int i=1;i<n;i++)
		add(a[i],b[i]),add(b[i],a[i]);
	for(int i=1;i<n+1;i++)
		if(cnt[i]%2) tot++;
	if(tot==2||tot==0)
	{
		memcpy(cur,head,sizeof(int[n+1]));
		if(tot==2)
		{ 
			for(int i=1;i<=n;i++)
				if(cnt[i]%2)
				{
					dfs(i);
					break;
				}
		}
		else
			dfs(1);
		if(coun!=n)
		{
			printf("-1");
			return 0;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",rev[c[i]]);
		return 0;
	}
	printf("-1");
	return 0;
}