#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

ll n, m, a, b;

void answer(){
    ll rest = n % m;
    std::cout << std::min(rest * b, (m - rest) * a) << std::endl;
}

void read(){
    std::cin >> n >> m >> a >> b;
}

int main(){
    read();
    answer();
    return 0;
}