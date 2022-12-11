#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int T,n;
int a[maxn];
vector<int> v[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)v[i].clear();
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),v[a[i]].push_back(i);
		int ans=n+1;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<v[i].size();++j)ans=min(ans,v[i][j]-v[i][j-1]+1);
		}
		if(ans==n+1)ans=-1;
		printf("%d\n",ans);
	}
}