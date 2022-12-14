
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a (n);
    bool existcont = false;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << ((
        a[0] % 2 != 0 &&
        a[n-1] % 2 != 0 &&
        n % 2 != 0
        ) ? "Yes" : "No") << '\n';
}