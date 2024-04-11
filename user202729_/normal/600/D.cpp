#include <iostream>
#include <iomanip>
#include <cmath>

#define debug(x) std::cout << x << "\n";

using ll = long long;
using num_t = long double;

//ll sqr(int a) {return static_cast<ll>(a)*a;}
num_t sqr(num_t a) {return a*a;}

//http://codeforces.com/contest/600/problem/D
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	num_t x1, y1, r1, x2, y2, r2;
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	num_t sqrd = sqr(x1 - x2) + sqr(y1 - y2);
	if (sqrd >= sqr(r1+r2)) {
		std::cout << '0';
		return 0;
	}
	if (sqrd <= sqr(r1 - r2)) {
        std::cout << std::fixed << std::setprecision(15) << sqr(std::min(r1, r2)) * 3.1415926535897932384626;
        return 0;
	}
	num_t d = std::sqrt(sqrd);
	//std::cout << std::fixed << std::setprecision(15) << std::asin(h / r2) * sqr(r2) + std::asin(h / r1) * sqr(r1) - 2 * s;

	num_t a = std::acos((sqr(r2)+sqrd-sqr(r1))/(2*d*r2)),
          b = std::acos((sqr(r1)+sqrd-sqr(r2))/(2*d*r1));

	std::cout <<
	(a - std::sin(2*a)/2) * sqr(r2) +
	(b - std::sin(2*b)/2) * sqr(r1)  << "\n";
	return 0;
}