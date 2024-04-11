#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>

typedef std::pair<int,int> ii;
typedef long long int ll;

const int ms=2*int(1e5)+10;

int n,k,s,t;
ii cars[ms];
int g[ms];
int length[ms];

bool can_get(int cap)
{
	ll cur_ans=0;
	for(int i=0;i<k;i++)
	{
		if(cap<length[i])
			return false;
		int left=0;
		int right=length[i];
		/*while(left!=right)
		{
			int mid=(left+right+1)/2;
			int cost=2*mid+(length[i]-mid);
			if(cost>cap)
				right=mid-1;
			else
				left=mid;
		}*/
		left=cap-length[i];
		int fast=std::min(length[i],left);
		int slow=length[i]-fast;
		//std::cout << i << ":fast " << fast << ", slow " << slow << '\n';
		cur_ans+=fast+2*slow;
	}
	//std::cout << "on cap " << cap << " took " << cur_ans << '\n';
	return cur_ans<=t;
}

int main()
{
	std::cin >> n >> k >> s >> t;
	for(int i=0;i<n;i++)
	{
		scanf("%i %i",&cars[i].first,&cars[i].second);
		cars[i].second=-cars[i].second;
	}
	std::sort(cars,cars+n);
	
	for(int i=0;i<k;i++)
	{
		scanf("%i",g+i);
		//std::cout << "g[" << i << "]=" << g[i] << '\n';
	}
	std::sort(g,g+k);
	g[k++]=s;
	length[0]=g[0];
	for(int i=1;i<k;i++)
	{
		length[i]=g[i]-g[i-1];
	}
	/*for(int i=0;i<k;i++)
		std::cout << "length " << i << "=" << length[i] << '\n';*/
	for(int i=0;i<n;i++)
		cars[i].second=-cars[i].second;

	int left=1;
	int right=int(1e9)+10;
	while(left!=right)
	{
		int mid=(left+right)/2;
		if(can_get(mid))
			right=mid;
		else
			left=mid+1;
	}
	for(int i=0;i<n;i++)
	{
		if(cars[i].second>=left)
		{
			std::cout << cars[i].first << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";


	/*ll cur_ans=0;
	int cur_car=0;
	ll wasted_time=0;
	int cur_cap=cars[0].second;
	std::priority_queue<int,std::vector<int>,std::greater<int> > hp;*/
	/*for(int i=0;i<k;i++)
	{
		if(2*car_cap<length[i])
		{
			for(int j=cur_car+1;j<=n;j++)
			{
				if(j==n)
				{
					std::cout << "-1\n";
					return 0;
				}
				if(2*cars[j].second>=length)
				{
					int diff=cars[j].second-car_cap;
					while(!hp.empty() && )
				}
			}
		}
		int left=0;
		int right=length;
		while(left!=right)
		{
			int mid=(left+right+1)/2;
			int cost=2*mid+(length[i]-mid);
			if(cost>car_cap)
				right=mid-1;
			else
				left=mid;
		}
		int fast=left;
		int slow=length[i]-left;
		cur_ans+=fast+2*slow;
		wasted_time+=slow;
		hp.push(slow);
	}*/
}