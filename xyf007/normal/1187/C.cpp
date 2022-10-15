#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
int n,m,a[1001];
bool mark[1001];
std::vector<std::pair<int,int> >v;
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if(!t)
		{
			v.push_back(std::make_pair(l,r));
		}
		else
		{
			for(int i=l; i<r; i++)
			{
				mark[i]=1;
			}
		}
	}
	for(std::vector<std::pair<int,int> >::iterator it=v.begin(); it!=v.end(); it++)
	{
		int l=it->first,r=it->second,now=1;
		for(int i=l; i<r; i++)
		{
			now&=mark[i];
		}
		if(now)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n%d ",a[1]=1000);
	for(int i=1; i<n; i++)
	{
		if(mark[i])
		{
			printf("%d ",a[i+1]=a[i]);
		}
		else
		{
			printf("%d ",a[i+1]=a[i]-1);
		}
	}
	return 0;
}