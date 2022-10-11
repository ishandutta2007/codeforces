#include <iostream>
#include <algorithm>

typedef long long ll;

const int ms = 100100;

int a[ms];

ll triple(ll x)
{
	return x * (x - 1) * (x - 2) / 6;
}

ll comb(ll x)
{
	return x * (x - 1) / 2;
}

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a, a + n);
	int freq[3] = {0, 0, 0};
	for(int i = 0; i < 3; i++)
	{
		freq[i]++;
		while(freq[i] < n && a[freq[0] + freq[1] + freq[2]] == a[freq[0] + freq[1] + freq[2] - 1])
			freq[i]++;
		if(freq[i] == n)
			break;
	}
	if(freq[0] >= 3)
		std::cout << triple(freq[0]) << '\n';
	else if(freq[0] + freq[1] >= 3)
	{
		if(freq[0] == 1)
			std::cout << comb(freq[1]) << '\n';
		else
			std::cout << comb(freq[0]) * freq[1] << '\n';
	}
	else
		std::cout << freq[0] * freq[1] * freq[2] << '\n';
}