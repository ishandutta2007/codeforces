#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a.begin(),a.end());
		int ans=1e9;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				for(int k=j+1;k<n;++k)
					ans=min(ans,a[k]-a[i]);
		printf("%d\n",ans);
	}
	return 0;
}