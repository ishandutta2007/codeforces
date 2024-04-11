#include <iostream>

const int ms=100100;

typedef long long int ll;

ll freq[ms];

ll memo[ms];

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		int temp;
		std::cin >> temp;
		freq[temp]++;
	}
	memo[1]=freq[1];
	for(int i=2;i<ms;i++)
		memo[i]=std::max(memo[i-2]+freq[i]*i, memo[i-1]);
	std::cout << memo[ms-1] << '\n';
}