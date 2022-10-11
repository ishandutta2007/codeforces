#include <iostream>
#include <cmath>
#include <iomanip>

typedef long double ld;

const ld PI = acosl(-1);

int main()
{
	int q, r, v;
	std::cin >> q >> r >> v;
	ld rr = r, vv = v;
	std::cout << std::fixed << std::setprecision(20);
	while(q--)
	{
		int s, f;
		std::cin >> s >> f;
		ld ans = 0.0;
		ld delta = (f - s) / rr;
		ans += (int)((delta) / (2 * PI));
		ans = ans * (2 * PI);
		delta -= ans;
		ld l = 0, r = 2 * PI;
		for(int i = 0; i < 100; i++)
		{
			ld mid = (l + r) / 2;
			if(mid - sinl(mid) > PI - delta / 2)
				r = mid;
			else
				l = mid;
		}
		ld add = 2 * (PI - l);
		ans += add;
		std::cout << (ans / (vv / rr)) << '\n';
	}
}