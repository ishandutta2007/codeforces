#include <bits/stdc++.h>

int main(){
    std::string n;
    std::cin >> n;
    int x;
    std::cin >> x;
    if (n == "ABC"){
        std::cout << (x <= 1999 ? "Yes" : "No") << "\n";
    }
    else if (n == "ARC"){
        std::cout << (x <= 2799 ? "Yes" : "No") << "\n";
    }
    else if (n == "AGC"){
        std::cout << (x >= 1200 ? "Yes" : "No") << "\n";
    }
}