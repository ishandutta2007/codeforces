#include <iostream>
#include <iomanip>

double fix(double pos, double len)
{
	int got = int(pos / len);
	pos = pos - got * len;
	if(got % 2 == 0)
		return pos;
	else
		return len - pos;
}

int main()
{
	std::cout << std::fixed << std::setprecision(20);
	double a, b, m;
	double vx, vy, vz;
	std::cin >> a >> b >> m >> vx >> vy >> vz;
	double tim = m / -vy;
	double xpos = a / 2 + vx * tim, zpos = vz * tim;
	if(xpos < 0)
		xpos = -xpos;
	if(zpos < 0)
		zpos = -zpos;
	xpos = fix(xpos, a);
	zpos = fix(zpos, b);
	std::cout << xpos << ' ' << zpos << '\n';
}