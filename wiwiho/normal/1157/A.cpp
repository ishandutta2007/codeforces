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

int f(int x){
    x += 1;

    while(x % 10 == 0){
        x /= 10;
    }

    return x;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    int ans = 1;
    std::set<int> reachable;
    reachable.insert(n);
    
    while(reachable.find(f(n)) == reachable.end()){
        ans++;
        n = f(n);
        reachable.insert(n);
    }

    std::cout << ans << "\n";

    return 0;
}