#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int> a(n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		int sum=0;
		for(int i=0;i<n;++i)
			sum+=a[i];
		puts(sum?"YES":"NO");
	}
	return 0;
}