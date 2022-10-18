#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

//#define TEST

long long gcd(long long a, long long b){
    long long t = 1;
    while(t != 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    long long a, b;
    std::cin >> a >> b;

    if(a > b){
        std::swap(a, b);
    }

    long long distance = b - a;

    std::vector<long long> q;
    for(long long i = 1; i * i <= distance; i++){
        if(distance % i == 0){
            q.push_back(i);
            if(i * i != distance){
                q.push_back(distance / i);
            }
        }
    }

    long long ans = 0;
    long long lcm = 1000000000000000000;

    std::sort(q.begin(), q.end());

    for(int i = 0; i < q.size(); i++){

        if(b % q[i] != a % q[i]){
            continue;
        }

        long long k = (q[i] - a % q[i]) % q[i];
        
        long long temp = (a + k) * (b + k) / gcd(a + k, b + k);

        if(temp < lcm){
            lcm = temp;
            ans = k;
        }

    }

    std::cout << ans << "\n";

    return 0;
}