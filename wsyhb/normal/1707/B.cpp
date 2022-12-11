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
		int cnt=0;
		vector<int> v;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			if(a)
				v.push_back(a);
			else
				++cnt;
		}
		while(cnt+int(v.size())>1)
		{
			vector<int> v_now;
			int cnt_now=0;
			for(int i=0;i+1<int(v.size());++i)
			{
				if(v[i]<v[i+1])
					v_now.push_back(v[i+1]-v[i]);
				else
					++cnt_now;
			}
			if(cnt>0&&!v.empty())
				v_now.push_back(v[0]);
			if(cnt>1)
				cnt_now+=cnt-1;
			sort(v_now.begin(),v_now.end());
			cnt=cnt_now;
			v.swap(v_now);
		}
		if(cnt==1)
			puts("0");
		else
			printf("%d\n",v[0]);
	}
	return 0;
}