#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, k;
	while(std::cin >> n >> k)
	{
		std::vector<int> a(n, 0);
		for(int i = 0; i < n; i++)
				std::cin >> a[i];
		if(k > 1)
		{
			while(k--)
				std::cin >> n;
			std::cout << "Yes\n";
			continue;
		}
		if(k == 1)
		{
			
			
			int num;
			std::cin >> num;
			for(int i = 0; i < n; i++)
				a[i] = a[i] == 0 ? num : a[i];
		}
		std::vector<int> b = a;
		std::sort(b.begin(), b.end());
		if(b == a)
			std::cout << "No\n";
		else
			std::cout << "Yes\n";
	}
}