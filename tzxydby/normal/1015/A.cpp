#include<bits/stdc++.h>
using namespace std;
bool a[105];
vector<int>ans;
int main()
{
	int n,m,l,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
			a[j]=true;
	}
	for(int i=1;i<=m;i++)
		if(!a[i])
			ans.push_back(i);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}