#include <iostream>
#include <vector>

typedef long long ll;

ll m, b, result = -1;

int main() {
    std::cin >> m >> b;
    for (ll y = 0; y <= b; ++y) {
        ll x = m * (b - y);
        result = std::max(result, ((x+1)*(y+1)*(x+y))/2);
    }
    std::cout << result << "\n";
}