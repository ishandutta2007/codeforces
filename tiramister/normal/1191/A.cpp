#include <iostream>
#include <string>

const std::string grade = "DACB";

int main() {
    int x;
    std::cin >> x;
    x %= 4;

    int d = 0;
    for (int i = 1; i <= 2; ++i) {
        if (grade[(x + i) % 4] < grade[(x + d) % 4]) d = i;
    }

    std::cout << d << " " << grade[(x + d) % 4] << std::endl;
    return 0;
}