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
#include <stdlib.h>

long long gcd(long long a, long long b){
    while(b != 0){
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long n, k, a, b;
    std::cin >> n >> k >> a >> b;

    long long s = 1 + a;
    long long first = 1 + b;

    bool front = true;
    long long min = 10000000000;
    long long max = 0;
    while(first <= n * k){
        long long l = s == first ? n * k : abs(s - first);
        long long times = n * k / gcd(l, n * k);
        #ifdef TEST
        std::cout << first << " " << l << " " << times << "\n";
        #endif
        min = std::min(min, times);
        max = std::max(max, times);
        if(front){
            first += k - 2 * b;
        }
        else{
            first += 2 * b;
        }
        front = !front;
    }

    std::cout << min << " " << max << "\n";

    return 0;
}