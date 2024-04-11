#include <iostream>
#include <cstdio>
#include <map>

std::map<int, int> wtf;

int main()
{
	int n;
	int max, min;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		int temp;
		//std::cin >> temp;
		scanf("%i",&temp);
		wtf[temp]++;
		if(i==0 || temp>max)
			max=temp;
		if(i==0 || temp<min)
			min=temp;
	}
	if(max==min)
		std::cout << "0\n";
	else
		std::cout << n-wtf[min]-wtf[max] << '\n';

}