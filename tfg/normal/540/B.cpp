#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cstdlib>

int a[1010];

int main()
{
	//srand(time(NULL));
	int n, k, p, x, y;
	std::cin >> n >> k >> p >> x >> y;
	/*n = rand() % 999;
	if(n % 2 == 0)
		n++;
	k = rand() % n + 1;
	p = rand() % 1000 + 1;
	x = rand() % (n * p) + 1;
	y = rand() % p + 1;*/
	//std::cout << "(" << n << ", " << k << ", " << p << ", " << x << ", " << y << ")\n";
	int from = k;
	int sum = 0;
	int great = 0;
	int less = 0;
	int equal = 0;
	for(int i = 0; i < k; i++)
	{
		std::cin >> a[i];
		//a[i] = rand() % p + 1;
		//std::cout << "got " << a[i] << "\n";
		sum += a[i];
		if(a[i] >= y)
			great++;
		else if(a[i] == y)
			equal++;
		else
			less++;
	}
	if(less > n / 2)
	{
		std::cout << "-1\n";
		return 0;
	}
	int use = std::min(n / 2 - less, n - k);
	less += use;
	sum += use;
	while(use--)
		a[k++] = 1;
	use = n - k;
	sum += use * y;
	while(use--)
		a[k++] = y;
	if(sum > x)
	{
		std::cout << "-1\n";
		return 0;
	}
	for(int i = from; i < n; i++)
	{
		if(i != from)
			std::cout << ' ';
		std::cout << a[i];
	}
	std::cout << "\n";
	std::sort(a, a + n);
	assert(a[n / 2] >= y);
	assert(sum <= x);
}