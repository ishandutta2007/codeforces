#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=2021+5;
int a[max_n];
vector<int> ans;
inline int find(int x)
{
	assert(x>=1&&x<=n);
	for(int i=1;i<=x;++i)
	{
		if(a[i]==x)
			return i;
	}
	assert(false);
	return -1;
}
inline void work(int x)
{
	assert(x>=1&&x<=n&&(x&1));
	ans.push_back(x);
	reverse(a+1,a+x+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool flag_exist=true;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			if((a[i]^i)&1)
				flag_exist=false;
		}
		if(!flag_exist)
		{
			puts("-1");
			continue;
		}
		ans.clear();
		for(int i=n;i>=3;i-=2)
		{
			if(a[i-1]==i-1&&a[i]==i)
				continue;
			if(a[1]!=i)
				work(find(i));
			if(a[2]!=i-1)
			{
				work(find(i-1)-1);
				work(find(i-1)+1);
				assert(a[2]==i-1&&a[3]==i);
				work(3);
			}
			work(i);
		}
		printf("%d\n",int(ans.size()));
		for(int i=0;i<int(ans.size());++i)
			printf("%d%c",ans[i],i+1<(int)ans.size()?' ':'\n');
	}
	return 0;
}