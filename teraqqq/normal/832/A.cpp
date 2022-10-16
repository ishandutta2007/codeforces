#include <iostream>
#include <algorithm>

long long n, k;
int main()
{
    std::cin >> n >> k;
    std::cout << (n % k - n % (2*k) ? "YES" : "NO");
}