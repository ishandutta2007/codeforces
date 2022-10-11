#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::pair<double, double> dd;

inline int readint()
{
	int temp;
	scanf("%i",&temp);
	return temp;
}

ii a[1010];

int main()
{
	int n=readint();
	for(int i=0;i<n;i++)
	{
		a[i].first=readint();
		a[i].second=i+1;
	}
	std::sort(a,a+n);
	for(int i=0;i<n-i-1;i++)
		printf("%i %i\n",a[i].second,a[n-i-1].second);
}