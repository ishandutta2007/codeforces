#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		set<int>s;
		vector<int>v;
		int n;
		scanf("%d",&n);
		while(n--)
		{
			int x;
			scanf("%d",&x);
			if(s.count(x))
				v.push_back(x);
			else
				s.insert(x);
		}
		for(auto i:s)
			printf("%d ",i);
		for(auto i:v)
			printf("%d ",i);
		puts("");
	}
	return 0;
}