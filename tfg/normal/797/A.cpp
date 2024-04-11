#include <iostream>

int size = 0;
int expo[50];
int prime[50];
int ans[50];

int main()
{
	int n, k;
	while(std::cin >> n >> k)
	{
		int tot = 0;
		size = 0;
		for(int i = 2; i <= n; i++)
		{
			int e = 0;
			while(n % i == 0)
			{
				n /= i;
				e++;
			}
			if(!e)
				continue;
			tot += e;
			expo[size] = e;
			prime[size] = i;
			size++;
		}
		if(tot < k)
		{
			std::cout << "-1\n";
			continue;
		}
		for(int i = 0; i < k; i++)
			ans[i] = 1;
		for(int i = 0; i < size && tot >= k; i++)
		{
			while(expo[i] && tot >= k)
			{
				expo[i]--;
				tot--;
				ans[0] *= prime[i];
			}
		}
		int c = 1;
		for(int i = 0; i < size; i++)
		{
			while(expo[i])
			{
				expo[i]--;
				ans[c++] = prime[i];
			}
		}

		for(int i = 0; i < k; i++)
		{
			if(i)
				std::cout << " ";
			std::cout << ans[i];
		}
		std::cout << '\n';
	}
}