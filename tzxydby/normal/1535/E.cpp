#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,a[N],c[N],fa[N][19],d[N];
int main()
{
	scanf("%d%d%d",&n,&a[0],&c[0]);
	for(int x=1;x<=n;x++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d%d",&fa[x][0],&a[x],&c[x]);
			d[x]=d[fa[x][0]]+1;
			for(int j=1;j<=18;j++)
				fa[x][j]=fa[fa[x][j-1]][j-1];
		}
		else
		{
			int v,w;
			scanf("%d%d",&v,&w);
			int s1=0;
			long long s2=0;
			while(s1!=w&&a[v])
			{
				int u=v;
				for(int j=18;j>=0;j--)
					if(d[u]>=(1<<j)&&a[fa[u][j]])
						u=fa[u][j];
				int k=min(w-s1,a[u]);
				a[u]-=k;
				s1+=k;
				s2+=1ll*k*c[u];
			}
			printf("%d %lld\n",s1,s2);
		}
		fflush(stdout);
	}
	return 0;
}