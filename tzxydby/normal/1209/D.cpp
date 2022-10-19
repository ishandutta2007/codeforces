#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,fa[N],ans;
int find(int a){return (fa[a]==a?a:fa[a]=find(fa[a]));}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(find(u)==find(v))
		{
			ans++;
			continue;
		}
		fa[find(u)]=find(v);
	}
	printf("%d\n",ans);
	return 0;
}