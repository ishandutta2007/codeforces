#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <utility>

typedef long long ll;

std::vector<ll> a, left;

int n, k;

ll aabs(ll x)
{
	if(x<0)
		return -x;
	return x;
}

ll solve(int l, int r)
{
	//std::cout << "on (" << l << ", " << r << ")\n";
	if(l==r)
	{
		if(k==1)
			return a[l]==1;
		else if(k==-1)
			return a[l]==1 || a[l]==-1;
		ll cur_k=1;
		while(aabs(cur_k)<=aabs(a[l]))
		{
			if(cur_k==a[l])
				return true;
			cur_k*=k;
		}
		return false;
	}
	
	left.clear();
	ll sum=0;
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++)
		sum+=a[i];
	for(int i=l;i<=mid;i++)
	{
		if(k==1)
			left.push_back(1-sum);
		else if(k==-1)
		{
			left.push_back(1-sum);
			left.push_back(-1-sum);
		}
		else
		{
			for(ll cur_k=1;aabs(cur_k)-aabs(sum)<=(ll)(r-mid+3)*ll(1e9)+10;cur_k*=k)
			{
				left.push_back(cur_k-sum);
			}
		}
		sum-=a[i];
	}
	sum=0;
	ll ans=0;
	std::sort(left.begin(), left.end());
	for(int i=mid+1;i<=r;i++)
	{
		sum+=a[i];
		ans+=int(std::upper_bound(left.begin(), left.end(), sum) - std::lower_bound(left.begin(), left.end(), sum));
	}
	//int temp;
	//std::cin >> temp;
	return ans+solve(l, mid)+solve(mid+1,r);
}


int main()
{
	std::cin >> n >> k;
	if(n==-1)
	{
		n=100000;
		k=2;
		for(int i=1;i<=n;i++)
			a.push_back(i);
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			ll temp;
			scanf("%lli",&temp);
			a.push_back(temp);
		}
	}
	//if(k==1)
	//	std::cout << ((ll)n*(ll)(n+1))/2 << '\n';
	std::cout << solve(0, n-1) << '\n';
}