#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
//faster input

int n, n1, n2;

int a[100100];

int main()
{
	scanf("%i %i %i",&n,&n1,&n2);
	for(int i=1;i<=n;i++)
	{
		scanf("%i",a+i);
		a[i]=-a[i];
	}
	std::sort(a+1,a+1+n);

	long long int sum=0;
	for(int i=1;i<=n1;i++)
	{
		sum-=a[i];
		//std::cout << "1: " << -a[i] << '\n';
	}
	double ans1=(double)sum/(double)n1;
	sum=0;
	for(int i=n1+1;i<=n1+n2;i++)
		sum-=a[i];
	ans1+=(double)sum/(double)n2;

	sum=0;
	for(int i=1;i<=n2;i++)
	{
		sum-=a[i];
		//std::cout << "1: " << -a[i] << '\n';
	}
	double ans2=(double)sum/(double)n2;
	sum=0;
	for(int i=n2+1;i<=n1+n2;i++)
		sum-=a[i];
	ans2+=(double)sum/(double)n1;

	std::cout << std::fixed << std::setprecision(10) << std::max(ans1,ans2) << '\n';

}