#include <iostream>

int n,m;

int a[1010];
int sum[1010];

int main()
{
	std::cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		std::cin >> a[i];
		sum[i]=a[i]+sum[i-1];
	}
	long long int ans=0;
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		std::cin >> t1 >> t2;
		int cur_sum=sum[t2]-sum[t1-1];
		if(cur_sum>=0)
			ans+=cur_sum;
	}
	std::cout << ans << '\n';
}