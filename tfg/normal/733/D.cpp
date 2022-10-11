#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

typedef long long int ll;
typedef std::pair<ll, ll> ii;
typedef std::pair<ii, ii> iii;

std::vector<iii> blocks;

ll a[3];

int main()
{
	int n;
	scanf("%i", &n);
	ll ans1=0;
	int ind1=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%lli",a+j);
		}
		std::sort(a,a+3);
		if(a[0]>ans1)
		{
			ans1=a[0];
			ind1=i;
		}
		blocks.push_back(iii(ii(a[1]*a[2],a[1]),ii(a[0],i)));
	}
	std::sort(blocks.begin(),blocks.end());
	ll ans2=0;
	int ind21=-1;
	int ind22=-1;
	for(int i=1;i<n;i++)
	{
		if(blocks[i].first.first!=blocks[i-1].first.first) continue;
		if(blocks[i].first.second!=blocks[i-1].first.second) continue;
		ll nl=std::min(blocks[i].first.second, blocks[i].second.first+blocks[i-1].second.first);
		if(nl>ans2)
		{
			ind21=blocks[i].second.second;
			ind22=blocks[i-1].second.second;
			ans2=nl;
		}
	}
	if(ans1>=ans2)
	{
		std::cout << "1\n" << ind1+1;
	}
	else
	{
		std::cout << "2\n" << ind21+1 << ' ' << ind22+1;
	}
	std::cout << std::endl;
}