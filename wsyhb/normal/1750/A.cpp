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
		puts(a[0]==1?"Yes":"NO");
	}
	return 0;
}