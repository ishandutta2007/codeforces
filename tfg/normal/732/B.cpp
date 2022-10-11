#include <iostream>
#include <algorithm>

int n,k;
int a[1010];

int sum(int x)
{
	if(n==1) return a[0];
	if(x==n-1) return a[n-1]+a[n-2];
	return a[x]+a[x+1];
}

int main()
{
	std::cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		std::cin >> a[i];
	}
	int ans=0;
	for(int i=0;i<n-1;i++)
	{
		if(sum(i)>=k) continue;
		int nxt=std::min(n-1,i+1);
		int rest=k-sum(i);
		a[nxt]+=rest;
		ans+=rest;
	}
	std::cout << ans << std::endl << a[0];
	for(int i=1;i<n;i++)
		std::cout << ' ' << a[i];
	std::cout << std::endl;
}