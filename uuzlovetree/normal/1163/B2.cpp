#include<bits/stdc++.h>
using namespace std;
int n;
int vis[100005];
int maxv,minv;
int has[100005];
int num;
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		if(vis[x])has[vis[x]]--;
		vis[x]++;
		maxv=max(maxv,vis[x]);
		has[vis[x]]++;
		bool yes=0;
		if(has[maxv]==1&&has[maxv-1]*(maxv-1)==i-maxv)
		{
			yes=1;
		}
		else if(has[1]==1&&has[maxv]*maxv==i-1)
		{
			yes=1;
		}
		else if(maxv==1)
		{
			yes=1;
		}
		if(yes)ans=i;
	}
	printf("%d\n",ans);
}