#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		s.clear();
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			s.insert(x);
		}
		printf("%d\n",s.size());
	}
	return 0;
}