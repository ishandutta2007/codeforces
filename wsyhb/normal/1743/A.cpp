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
		a.resize(unique(a.begin(),a.end())-a.begin());
		int cnt=10-(int)a.size();
		int ans=cnt*(cnt-1)*3;
		printf("%d\n",ans);
	}
	return 0;
}