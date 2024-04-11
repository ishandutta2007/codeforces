#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <string.h>

#define MODULO 1000000007LL

//#define TEST

long long f(long long x){
    long long two = 1;
    int exp = 0;
    long long even = 0;
    long long odd = 0;
    //std::cerr << x << "\n";
    while(x > 0){
        if(exp % 2 == 0){
            odd += std::min(two, x);
        }
        else{
            even += std::min(two, x);
        }
        //std::cerr << x << " " << even << " " << odd << " " << exp << " " << two << "\n";
        x -= two;
        two *= 2;
        exp++;
    }

    //std::cerr << x << " " << even << " " << odd << "\n";

    return ((((even % MODULO) * ((even + 1) % MODULO)) % MODULO) + (((odd % MODULO) * (odd % MODULO)) % MODULO)) % MODULO;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    long long l, r;
    std::cin >> l >> r;

    long long temp = f(r) - f(l - 1);
    if(temp < 0){
        temp = MODULO + temp;
    }
    std::cout << temp << "\n";

    return 0;
}