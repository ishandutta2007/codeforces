#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=1e5+5;
vector<int> G[N];
int ans[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(i);
		G[v].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(G[i].size()>=3)
		{
			ans[G[i][0]]=0;
			ans[G[i][1]]=1;
			ans[G[i][2]]=2;
			int now=2;
			for(int j=1;j<n;j++)
				if(j!=G[i][0]&&j!=G[i][1]&&j!=G[i][2]) ans[j]=++now;
			for(int j=1;j<n;j++) printf("%d\n",ans[j]);
			return 0;
		}
	for(int j=1;j<n;j++) printf("%d\n",j-1);
	return 0;
}