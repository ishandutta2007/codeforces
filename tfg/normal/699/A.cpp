#include <cstdio>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::pair<double, double> dd;

inline int readint()
{
	int temp;
	scanf("%i",&temp);
	return temp;
}

ii a[200100];

int main()
{
	int n=readint();
	std::string str;
	std::cin >> str;
	for(int i=0;i<n;i++)
	{
		a[i].first=readint();
		a[i].second=(str[i]=='R'?1:0);
	}
	std::sort(a, a+n);
	int ans=1000100000;
	for(int i=0;i<n-1;i++)
	{
		if(a[i].second==1 && a[i+1].second==0)
			ans=std::min(ans, (a[i+1].first-a[i].first)/2);
	}
	printf("%i\n",ans<1000100000?ans:-1);

}