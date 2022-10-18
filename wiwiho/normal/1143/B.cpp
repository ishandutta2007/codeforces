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

long long ten[11] = {1, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

long long pow9(int n){
    long long ans = 1;
    for(int i = 0; i < n; i++){
        ans *= 9;
    }
    return ans;
}

long long calc(long long n){
    //std::cerr << n << "\n";
    int digit = 1;
    for(long long i = n; i /= 10, i > 0; digit++);
    //std::cerr << n << " " << digit << " " << (n % ten[digit]) << "\n";

    if(digit == 1){
        return n;
    }
    else{
        long long temp = n / ten[digit] - 1;
        temp = temp > 0 ? temp : 1;
        return std::max(calc(n % ten[digit]) * (n / ten[digit]), pow9(digit - 1) * temp);
    }
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long n;
    std::cin >> n;

    std::cout << calc(n) << "\n";

    return 0;
}