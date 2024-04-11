#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long ll;

ll a[100100];

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
		scanf("%lli", a+i);
	std::sort(a, a+n);
	for(int i=n-1;i>=2;i--)
	{
		if(a[i-1]+a[i-2]>a[i])
		{
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}