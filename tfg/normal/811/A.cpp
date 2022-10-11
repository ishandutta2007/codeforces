#include <iostream>

int main()
{
	int ans = 1;
	long long a[2];
	std::cin >> a[0] >> a[1];
	while(a[(ans & 1) ^ 1] >= ans)
	{
		//a[ans & 1] += ans;
		a[(ans & 1) ^ 1] -= ans;
		ans++;
	}
	if(ans & 1)
		std::cout << "Vladik\n";
	else
		std::cout << "Valera\n";
}