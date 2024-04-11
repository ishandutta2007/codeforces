#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,a[N],n;
vector<int>ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans.push_back(a[1]);
		int x=a[1]>a[2];
		for(int i=2;i<n;i++)
		{
			int y=a[i]>a[i+1];
			if(y!=x)
			{
				ans.push_back(a[i]);
				x=y;
			}
		}
		ans.push_back(a[n]);
		printf("%d\n",ans.size());
		for(auto i:ans)
			printf("%d ",i);
		puts("");
	}
	return 0;
}