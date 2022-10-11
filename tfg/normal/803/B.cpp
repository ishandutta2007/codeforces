#include <iostream>

const int ms = 200200;

int n;
int a[ms], l[ms], r[ms];

int main()
{
	std::cin >> n;
	for(int i = 1; i <= n; i++)
		std::cin >> a[i];
	l[0] = - 4 * ms;
	r[n + 1] = 4 * ms;
	for(int i = 1; i <= n; i++)
	{
		l[i] = l[i - 1];
		if(a[i] == 0)
			l[i] = i;
	}
	for(int i = n; i > 0; i--)
	{
		r[i] = r[i + 1];
		if(a[i] == 0)
			r[i] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		if(i != 1)
			std::cout << ' ';
		std::cout << std::min(i - l[i], r[i] - i);
	}
	std::cout << '\n';
}