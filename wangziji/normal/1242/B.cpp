#include <iostream>
#include <bitset>
#include <cstdlib>
using namespace std;
struct edge
{
	int v,n;
}e[200005];
int head[100005],cnt;
inline void add(int u,int v)
{
	e[++cnt].v=v,e[cnt].n=head[u];
	head[u]=cnt;
}
int fa[100005];
inline int ff(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=ff(fa[x]);
}
bitset <100005> t,now,E,vis,l,T;
int main(int argc, char** argv) {
	int n,m,ans=0;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++)
		l[i]=1;
	t[1]=vis[1]=1;
	int lst=1,cnt=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	fa[1]=2;
	for(int i=1;i<n;i++)
	{
		now.set();
		for(int j=head[lst];j;j=e[j].n)
			now[e[j].v]=0;
		t|=now;
		t&=l;
	//	cout << endl;
		T=t^vis;
		//for(int j=1;j<=n;j++)
	//		cout << T[j] << " ";
	//	cout << endl;;
		if(T==E)
		{
			int x;
			while(1)
			{
				int j=rand()*rand()%n+1;
				++cnt;
				if(vis[j]==0)
				{
					x=j;
					break;
				}
			}
			//cout << x << endl;
			vis[x]=1,++ans,lst=x;
		}
		else
		{
			int x;
			while(1)
			{
				int j=rand()*rand()%n+1;
				++cnt;
				if(T[j]==1)
				{
					x=j;
					break;
				}
			}
			//cout << x << endl;
			vis[x]=1,lst=x;
		}
	}
	cout << ans;
	return 0;
}