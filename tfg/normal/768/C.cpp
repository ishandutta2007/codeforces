#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

const int ms=2*1025;

int a[ms];
int b[ms];

int main()
{
	int n, k, x;
	std::cin >> n >> k >> x;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%i",&temp);
		a[temp]++;
	}
	for(int aa=0;aa<k;aa++)
	{
		memset(b, 0, sizeof b);
		int count=1;
		for(int i=0;i<ms;i++)
		{
			if(!a[i])
				continue;
			int use;
			if(count%2==1)
				use=(a[i]+1)/2;
			else
				use=a[i]/2;

			//std::cout << "from number " << i << ", count " << count << " using " << use << '\n';
			b[i]+=a[i]-use;
			b[i^x]+=use;
			count+=a[i];
		}
		for(int i=0;i<ms;i++)
			a[i]=b[i];
	}
	int min=ms+1;
	int max=-1;
	for(int i=0;i<ms;i++)
	{
		if(!a[i])
			continue;
		//std::cout << i << ": " << a[i] << '\n';
		min=std::min(min, i);
		max=std::max(max, i);
	}
	//std::cout << '\n';
	std::cout << max << ' ' << min << '\n';
}