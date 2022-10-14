#include <bits/stdc++.h>
int main() {
    int t; std::cin >> t;
    while(t--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (b - a%b) % b << '\n';
    }
}