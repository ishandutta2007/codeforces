#include <iostream>

int main() {
    long long n, m, a, p1, p2;
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;
    p1 = n;
    p1 --;
    p1 /= a;
    p1 ++;
    p2 = m;
    p2 --;
    p2 /= a;
    p2 ++;
    p1 *= p2;
    std::cout << p1;
}