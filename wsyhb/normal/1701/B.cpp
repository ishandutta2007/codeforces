#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
bool vis[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> ans;
		for(int i=1;i<=n;++i)
		{
			if(vis[i])
				continue;
			for(int j=i;j<=n;j<<=1)
			{
				assert(!vis[j]);
				ans.push_back(j);
				vis[j]=true;
			}
		}
		assert((int)ans.size()==n);
		puts("2");
		for(int i=0;i<n;++i)
			printf("%d%c",ans[i]," \n"[i==n-1]);
		for(int i=1;i<=n;++i)
			vis[i]=false;
	}
	return 0;
}