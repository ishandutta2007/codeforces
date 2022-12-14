#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    int nRemain = 0, nGiven = 0, a_i, nGivenToday, i;
    for (i = 0; i < n; ++i) {
        std::cin >> a_i;
        nRemain += a_i;
        nGivenToday = std::min(nRemain, 8);
        nGiven += nGivenToday; nRemain -= nGivenToday;
        if (nGiven >= k) break;
    }
    if (i == n) std::cout << "-1\n"; else std::cout << 1+i << '\n';
}