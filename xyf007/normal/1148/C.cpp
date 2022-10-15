#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
int n,a[300001],b[300001];
std::vector<std::pair<int,int> >ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]=i;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==i)
		{
			continue;
		}
		if(abs(b[i]-i)>=n/2)
		{
			ans.push_back(std::make_pair(std::min(b[i],i),std::max(b[i],i)));
			sum++;
		}
		else
		{
			if(abs(b[i]-1)>=n/2)
			{
				ans.push_back(std::make_pair(1,b[i]));
				sum++;
				if(abs(1-i)>=n/2)
				{
					ans.push_back(std::make_pair(1,i));
					ans.push_back(std::make_pair(1,b[i]));
					sum+=2;
				}
				else
				{
					ans.push_back(std::make_pair(1,n));
					ans.push_back(std::make_pair(i,n));
					ans.push_back(std::make_pair(1,n));
					ans.push_back(std::make_pair(1,b[i]));
					sum+=4;
				}
			}
			else
			{
				ans.push_back(std::make_pair(b[i],n));
				sum++;
				if(abs(n-i)>=n/2)
				{
					ans.push_back(std::make_pair(i,n));
					ans.push_back(std::make_pair(b[i],n));
					sum+=2;
				}
				else
				{
					ans.push_back(std::make_pair(1,n));
					ans.push_back(std::make_pair(1,i));
					ans.push_back(std::make_pair(1,n));
					ans.push_back(std::make_pair(b[i],n));
					sum+=4;
				}
			}
		}
		int t1=a[i];
		a[i]=i;
		a[b[i]]=t1;
		std::swap(b[t1],b[i]);
	}
	printf("%d\n",sum);
	for(std::vector<std::pair<int,int> >::iterator it=ans.begin();it!=ans.end();it++)
	{
		printf("%d %d\n",(*it).first,(*it).second);
	}
	return 0;
}