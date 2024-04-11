#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
std::set<int>s;
int n,a[100001];
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = i-1; j >=0; --j)
		{
			if (a[j]==(a[j]|a[i]))
			{
				break;
			}
			a[j]|=a[i];
			s.insert(a[j]);
		}
	}
	printf("%lld\n", (long long)s.size());
	return 0;
}