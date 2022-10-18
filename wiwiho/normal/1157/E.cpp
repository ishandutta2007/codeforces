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

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::map<int, int> b;
    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        b[temp]++;
    }

    for(int i = 0; i < n; i++){

        if(i != 0){
            std::cout << " ";
        }

        int ans = n;
        auto it = b.lower_bound(n - a[i]);
        if(it == b.end()){
            it = b.begin();
        }
        std::cout << ((a[i] + it->first) % n);
        (it->second)--;
        if(it->second == 0){
            b.erase(it->first);
        }

    }

    std::cout << "\n";

    return 0;
}