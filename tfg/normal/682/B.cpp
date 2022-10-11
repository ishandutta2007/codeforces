#include <cstdio>
#include <algorithm>
#include <vector>

std::vector<int> i_v;


int main()
{
	int n;
	scanf("%i",&n);
	i_v.resize(n);
	for(int i=0;i<n;i++)
	{
		int temp;scanf("%i",&temp);
		i_v[i]=temp;
	}
	std::sort(i_v.begin(), i_v.end());
	i_v[0]=1;
	for(int i=1;i<n;i++)
	{
		i_v[i]=std::min(i_v[i],i_v[i-1]+1);
	}
	printf("%i", i_v[n-1]+1);
}