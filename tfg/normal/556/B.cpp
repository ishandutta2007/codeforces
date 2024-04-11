#include <iostream>
#include <algorithm>

const int ms=1010;

int a[ms], dist[ms];

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::cin >> a[i];
		int to=i;
		if(i%2==0)
		{
			dist[i]=(to-a[i]+n)%n;
		}
		else
		{
			dist[i]=(a[i]-to+n)%n;
		}
	}
	std::sort(dist,dist+n);
	if(dist[0]==dist[n-1])
		std::cout << "Yes\n";
	else
		std::cout << "No\n";
}