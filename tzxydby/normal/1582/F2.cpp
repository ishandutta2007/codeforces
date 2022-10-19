#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=8205;
int n,f[M],g[M];
vector<int>p[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		p[x].push_back(i);
	}	
	for(int i=0;i<8192;i++)
		f[i]=n+1;
	f[0]=0;
	for(int i=0;i<=5000;i++)
	{
		for(int j=0;j<8192;j++)
			g[j]=n+1;
		if(p[i].size())
			g[i]=p[i][0];
		for(int j=0;j<8192;j++)
		{
			g[j]=min(g[j],f[j]);
			int x=lower_bound(p[i].begin(),p[i].end(),f[j]+1)-p[i].begin();
			if(x<p[i].size())
				g[j^i]=min(g[j^i],p[i][x]);
		}
		for(int j=0;j<8192;j++)
			f[j]=g[j];
	}
	for(int i=0;i<8192;i++)
		if(f[i]<=n)
			ans.push_back(i);
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%d ",i);
	return 0;
}