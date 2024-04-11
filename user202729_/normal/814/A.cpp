// problem a

#include <iostream>
#include <vector>

int lena, lenb;
std::vector<int> a, b;

int main() {
    std::cin >> lena >> lenb;
    a.resize(lena); b.resize(lenb);
    for (int i = 0; i < lena; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < lenb; ++i) {
        std::cin >> b[i];
    }

    if (lenb > 1) {
        std::cout << "Yes\n";
    } else {
        for (int i = 0; i < lena; ++i) {
            if (a[i] == 0) {
                a[i] = b[0];
                break;
            }
        }
        for (int i = 1; i < lena; ++i) {
            if (a[i-1] > a[i]) {
                std::cout << "Yes\n";
                return 0;
            }
        }
        // Oh no
        std::cout << "No\n";
    }
}