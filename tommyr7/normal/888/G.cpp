#include <bits/stdc++.h>
#define Maxn 6000007
using namespace std;
int n,a[Maxn],cnt,rt;
int f[Maxn][2],size[Maxn];
long long ans=0;
void insert(int &now,int val,int pos)
{
	if (!now) now=++cnt;
	if (pos<0) size[now]=1; else
	{
		if (val&(1<<pos)) insert(f[now][1],val,pos-1);
		else insert(f[now][0],val,pos-1);
		size[now]=size[f[now][1]]+size[f[now][0]];
	}
}
long long query(int x,int val,int pos)
{
	if (pos<0) return 0;
	if (val&(1<<pos))
	{
		if (f[x][1]) return query(f[x][1],val,pos-1);
		else return query(f[x][0],val,pos-1)+(1<<pos);
	} else
	{
		if (f[x][0]) return query(f[x][0],val,pos-1);
		else return query(f[x][1],val,pos-1)+(1<<pos);
	}
}
long long merge(int x,int y,int pos,int val,int r)
{
	if (pos<0) return query(y,val,r);
	long long res=(1<<30);
	if (f[x][0]) res=min(res,merge(f[x][0],y,pos-1,val,r));
	if (f[x][1]) res=min(res,merge(f[x][1],y,pos-1,val+(1<<pos),r));
	return res;
}
void dfs(int now,int pos)
{
	if (pos>=0)
	{
		if (f[now][0]) dfs(f[now][0],pos-1);
		if (f[now][1]) dfs(f[now][1],pos-1);
		if (f[now][0]&&f[now][1])
		{
			int x=f[now][0],y=f[now][1];
			if (size[x]>size[y]) swap(x,y);
			ans+=(1<<pos)+merge(x,y,pos-1,0,pos-1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		insert(rt,a[i],29);
	dfs(rt,29);
	printf("%lld\n",ans);
	return 0;
}