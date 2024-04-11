#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstring>
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

    long long n, m;
    std::cin >> n >> m;

    long long gcdt = -1;
    long long first;
    long long last;
    std::cin >> first;
    last = first;
    for(long long i = 1; i < n; i++){
        long long temp;
        std::cin >> temp;

        temp = temp - last;

        if(gcdt == -1){
            gcdt = temp;
        }
        else{
            gcdt = gcd(gcdt, temp);
        }
    }

    for(long long i = 0; i < m; i++){
        long long temp;
        std::cin >> temp;
        
        if(gcdt % temp == 0){
            std::cout << "YES\n";
            std::cout << first << " " << (i + 1) << "\n";
            return 0;
        }
    }

    std::cout << "NO\n";

    return 0;
}