#include <iostream>
#include <cstdio>

const int ms = 1001000;

int freq[ms];

int main()
{
	int n;
	std::cin >> n;
	while(n--)
	{
		int temp;
		scanf("%i", &temp);
		freq[temp]++;
	}
	int ans = 0;
	for(int i = 0; i < ms; i++)
	{
		freq[i + 1] += freq[i] / 2;
		freq[i] %= 2;
	}
	for(int i = 0; i < ms; i++)
		ans += freq[i];
	std::cout << ans << '\n';
}