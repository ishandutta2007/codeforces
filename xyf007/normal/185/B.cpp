#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int s, a, b, c;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> s >> a >> b >> c;
    if (!(a + b + c))
    {
        std::cout << "0.0 0.0 0.0";
        return 0;
    }
    double tot = a + b + c;
    std::cout << std::setprecision(12) << std::fixed << s * a / tot << ' ' << s * b / tot << ' ' << s * c / tot;
    return 0;
}