#include <iostream>

int a[1010];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	bool is = true;
	for(int i = 1; i < n; i++)
		is = is && a[i] - a[i - 1] == a[1] - a[0];
	if(is)
		std::cout << a[n - 1] + a[1] - a[0] << '\n';
	else
		std::cout << a[n - 1] << '\n';
}