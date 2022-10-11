#include <iostream>
#include <utility>
#include <iomanip>
#include <cmath>

typedef std::pair<double, double> dd;

dd me;
dd target;

double t;
double vmax;
dd v[2];

double dist(dd a, dd b)
{
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

bool can(double x)
{
	dd pos = me;
	double use = std::min(x, t);
	pos.first += v[0].first * use;
	pos.second+= v[0].second* use;
	use = x - use;
	pos.first += v[1].first * use;
	pos.second+= v[1].second* use;
	//std::cout << "on " << x << ", dist is " << dist(pos, target) << '\n';
	if(dist(pos, target) <= vmax * x)
		return true;
	else
		return false;
}

int main()
{
	std::cin >> me.first >> me.second;
	std::cin >> target.first >> target.second;
	std::cin >> vmax >> t;
	for(int i = 0; i < 2; i++)
		std::cin >> v[i].first >> v[i].second;
	double l = 0.0;
	double r = 1e9;
	for(int i = 0; i < 100; i++)
	{
		//std::cout << "on (" << l << ", " << r << ")\n";
		double mid = (l + r) / 2;
		if(can(mid))
			r = mid;
		else
			l = mid;
	}
	std::cout << std::fixed << std::setprecision(20) << l << '\n';
}