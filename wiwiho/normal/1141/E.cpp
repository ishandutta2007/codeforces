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
#include <typeinfo>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    long long h, n;
    std::cin >> h >> n;

    long long d[n];
    long long sum = 0;
    long long m = 0;
    long long hh = h;
    for(int i = 0; i < n; i++){
        std::cin >> d[i];
        sum -= d[i];

        hh += d[i];
        if(hh <= 0){
            std::cout << (i + 1) << "\n";
            return 0;
        }

        m = std::max(sum, m);
    }

    if(sum <= 0){
        std::cout << "-1\n";
        return 0;
    }

    long long round = (h - m) / sum;
    h -= round * sum;
    long long ans = round * n;

    for(int i = 0; ; i++){
        h += d[i % n];
        ans++;
        if(h <= 0){
            std::cout << ans << "\n";
            break;
        }
    }
    
    return 0;
}