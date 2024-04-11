#include <iostream>
#include <cstdio>
#include <utility>
#include <iomanip>

typedef long double ld;
typedef std::pair<ld, ld> dd;

const int ms = 100100;

int x[2], y[2];

int rx[ms], ry[ms], vx[ms], vy[ms];
ld interval[ms][2][2];
dd dude[ms];

int main()
{
	std::cout << std::fixed << std::setprecision(20);
	int n;
	std::cin >> n;
	for(int i = 0; i < 2; i++)
		scanf("%i %i", x + i, y + i);
	for(int i = 0; i < n; i++)
	{
		scanf("%i %i %i %i", rx + i, ry + i, vx + i, vy + i);
		//std::cout << "on (" << rx[i] << ", " << ry[i] << ")\n";
		//std::cout << "v is (" << vx[i] << ", " << vy[i] << ")\n";
		if(vx[i])
		{
			interval[i][0][0] = (-rx[i] + x[0]) / (ld)vx[i];
			interval[i][0][1] = (-rx[i] + x[1]) / (ld)vx[i];
			if(interval[i][0][0] > interval[i][0][1])
				std::swap(interval[i][0][0], interval[i][0][1]);
			//interval[i][0][0] = std::max(interval[i][0][0], (ld)0);
			//interval[i][0][1] = std::max(interval[i][0][1], (ld)0);
		}
		else if(rx[i] >= x[1] || rx[i] <= x[0])
		{
			std::cout << "-1\n";
			return 0;
		}
		else
		{
			interval[i][0][0] = 0;
			interval[i][0][1] = 1e20;
		}
		if(vy[i])
		{
			interval[i][1][0] = (-ry[i] + y[0]) / (ld)vy[i];
			interval[i][1][1] = (-ry[i] + y[1]) / (ld)vy[i];
			if(interval[i][1][0] > interval[i][1][1])
				std::swap(interval[i][1][0], interval[i][1][1]);
			//interval[i][1][0] = std::max(interval[i][1][0], (ld)0);
			//interval[i][1][1] = std::max(interval[i][1][1], (ld)0);
		}
		else if(ry[i] >= y[1] || ry[i] <= y[0])
		{
			std::cout << "-1\n";
			return 0;
		}
		else
		{
			interval[i][1][0] = 0;
			interval[i][1][1] = 1e20;
		}
		//std::cout << "(" << interval[i][0][0] << ", " << interval[i][0][1] << "), (" << interval[i][1][0] << ", " << interval[i][1][1] << ")\n";
		dude[i] = dd(std::max(interval[i][0][0], interval[i][1][0]), std::min(interval[i][0][1], interval[i][1][1]));
		//std::cout << "got (" << dude[i].first << ", " << dude[i].second << ")\n";
	}
	dd ans = dd(0, 1e20);
	for(int i = 0; i < n; i++)
	{
		ans.first = std::max(ans.first, dude[i].first);
		ans.second = std::min(ans.second, dude[i].second);
	}
	if(ans.second - ans.first < 1e-10)
		std::cout << "-1\n";
	else
		std::cout << (double) ans.first << '\n';
}