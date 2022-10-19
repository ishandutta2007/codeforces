#include<bits/stdc++.h>
using namespace std;
const int N=55;
int t,n,a[N];
set<int>s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		s.clear();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)	
				s.insert(a[j]-a[i]);
		printf("%d\n",s.size());
	}
	return 0;
}