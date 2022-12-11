#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
const int max_a=2.5e6+5;
vector<int> id[max_a];
int cnt[max_a];
vector<int> num;
const int max_2a=5e6+5;
int x[max_2a],y[max_2a];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		id[a[i]].push_back(i);
		++cnt[a[i]];
	}
	for(int i=1;i<=2.5e6;++i)
	{
		if(cnt[i])
			num.push_back(i);
	}
	for(int i=0;i<int(num.size());++i)
	{
		if(cnt[num[i]]>=4)
		{
			puts("YES");
			printf("%d %d %d %d\n",id[num[i]][0],id[num[i]][1],id[num[i]][2],id[num[i]][3]);
			return 0;
		}
		if(cnt[num[i]]>=2)
			x[num[i]<<1]=id[num[i]][0],y[num[i]<<1]=id[num[i]][1];
	}
	for(int i=0;i<int(num.size());++i)
		for(int j=i+1;j<int(num.size());++j)
		{
			if(cnt[num[i]]>1&&cnt[num[j]]>1)
			{
				puts("YES");
				printf("%d %d %d %d\n",id[num[i]][0],id[num[j]][0],id[num[i]][1],id[num[j]][1]);
				return 0;
			}
			if(x[num[i]+num[j]])
			{
				puts("YES");
				printf("%d %d %d %d\n",id[num[i]][0],id[num[j]][0],x[num[i]+num[j]],y[num[i]+num[j]]);
				return 0;
			}
			x[num[i]+num[j]]=id[num[i]][0],y[num[i]+num[j]]=id[num[j]][0];
		}
	puts("NO");
    return 0;
}