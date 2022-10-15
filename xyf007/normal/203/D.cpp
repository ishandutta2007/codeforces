#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int a, b, m, vx, vy, vz;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> a >> b >> m >> vx >> vy >> vz;
    double t = -m / static_cast<double>(vy), x = a / 2.0 + t * vx, z = t * vz;
    while (x < 0 || x > a)
    {
        if (x < 0)
        {
            x = -x;
        }
        else
        {
            x = 2 * a - x;
        }
    }
    while (z < 0 || z > b)
    {
        if (z < 0)
        {
            z = -z;
        }
        else
        {
            z = 2 * b - z;
        }
    }
    std::cout << std::setprecision(8) << std::fixed << x << ' ' << z;
    return 0;
}