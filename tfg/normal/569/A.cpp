#include <iostream>

int main()
{
	long long duration, to, speed;
	std::cin >> duration >> to >> speed;
	int ans = 0;
	while(to < duration)
	{
		long long use = to * speed;
		//std::cout << "using " << use << " time\n";
		to = to + to * (speed - 1);
		//std::cout << "to is now " << to << '\n';
		ans++;
	}
	std::cout << ans << '\n';
}