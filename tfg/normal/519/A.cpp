#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int eval(char ch) {
    if(ch == '.') {
        return 0;
    } else if('A' <= ch && ch <= 'Z') {
        return -eval(ch - 'A' + 'a');
    } else if(ch == 'p') return 1;
    else if(ch == 'r') return 5;
    else if(ch == 'n' || ch == 'b') return 3;
    else if(ch == 'q') return 9;
    else return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int ans = 0;
    for(int i = 0; i < 8; i++) {
        std::string str;
        std::cin >> str;
        for(auto ch : str) ans += eval(ch);
    }
    std::cout << (ans < 0 ? "White\n" : (ans > 0 ? "Black\n" : "Draw\n"));
}