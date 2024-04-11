#include <iostream>
#include <iomanip>

int n;
double power;
double a[100100], b[100100];

bool f(double x)
{
	double use = 0.0;
	for(int i = 0; i < n; i++)
	{
		double cur = b[i] - x * a[i];
		if(cur >= 0.0)
			continue;
		cur = -cur;
		use += cur / power;
	}
	//std::cout << "using " << use << '\n';
	if(use > x)
		return false;
	else
		return true;
}

int main()
{
	//std::cin.tie(0);
	//std::ios_base::sync_with_stdio(0);
	std::cout << std::fixed << std::setprecision(20);

	while(std::cin >> n >> power)
	{
		for(int i = 0; i < n; i++)
			std::cin >> a[i] >> b[i];
		double l = 0.0, r = 1e20;
		for(int j = 0; j < 100; j++)
		{
			double mid = (l + r) / 2.0;
			//std::cout << "(" << l << ", " << mid << ", " << r << ")\n";
			if(f(mid))
				l = mid;
			else
				r = mid;
		}
		if(l >= 1e19)
			std::cout << "-1\n";
		else
			std::cout << l << '\n';
	}
}