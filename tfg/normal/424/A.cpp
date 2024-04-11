#include <iostream>
#include <string>

int a[220];
int sum[2];

int main()
{
	int n;
	std::string str;
	std::cin >> n >> str;
	for(int i = 0; i < n; i++)
	{
		a[i] = (str[i] == 'x' ? 0 : 1);
		sum[a[i]]++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(sum[a[i]] > n / 2)
		{
			a[i] = 1 - a[i];
			sum[a[i]]++;
			sum[1 - a[i]]--;
			ans++;
		}
	}
	std::cout << ans << '\n';
	for(int i = 0; i < n; i++)
	{
		std::cout << (a[i] == 0 ? 'x' : 'X');
	}
	std::cout << '\n';
}