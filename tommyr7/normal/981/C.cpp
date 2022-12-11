#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,rt=0;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int d[Maxn];
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		insert(u,v),insert(v,u);
		++d[u],++d[v];
	}
	for (int i=1;i<=n;i++)
	{
		if (d[i]>2)
		{
			if (rt==0) rt=i;
			else
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	if (rt==0) rt=1;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (d[i]==1&&rt!=i) ++ans;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
		if (d[i]==1&&rt!=i) printf("%d %d\n",rt,i);
	return 0;
}