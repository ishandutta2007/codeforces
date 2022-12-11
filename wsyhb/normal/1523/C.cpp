#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> now;
		for(int i=1;i<=n;++i)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
				now.push_back(1);
			else
			{
				while(!now.empty()&&now.back()!=x-1)
					now.pop_back();
				assert(!now.empty());
				now.pop_back();
				now.push_back(x);
			}
			printf("%d",now[0]);
			for(int j=1;j<int(now.size());++j)
				printf(".%d",now[j]);
			printf("\n");
		}
	}
	return 0;
}