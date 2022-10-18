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

//#define TEST=

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    int k = m / n;

    if(n * k != m){
        std::cout << "-1\n";
        return 0;
    }

    int ans = 0;

    while(k % 2 == 0){
        k /= 2;
        ans++;
    }

    while(k % 3 == 0){
        k /= 3;
        ans++;
    }

    if(k != 1){
        std::cout << "-1\n";
    }
    else{
        std::cout << ans << "\n";
    }

    return 0;
}