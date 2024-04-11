#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,m,size[5005];
vector<int>s[5005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		s[a].push_back((b+n-a)%n);
	}
	for(int i=1;i<=n;i++)
	{
		sort(s[i].begin(),s[i].end());
		size[i]=s[i].size();
	}
	for(int st=1;st<=n;st++)
	{
		int ans=0;
		for(int j=0;j<n;j++)
		{
			if(size[(st+j-1)%n+1]==0)continue;
			ans=max(ans,size[(st+j-1)%n+1]*n+j-n+s[(st+j-1)%n+1][0]);
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}