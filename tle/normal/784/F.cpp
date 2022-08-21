#include <bits/stdc++.h>
int n,a[100003],i;main()
{
	std::cin>>n;
	for(i=1;i<=n;i++)std::cin>>a[i];
	long long p=clock();
	while(clock()-p<1400);
	std::sort(a+1,a+1+n);
	for(i=1;i<=n;i++)std::cout<<a[i]<<" ";
}