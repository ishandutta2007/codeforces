#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    int temp = 1;
    for(int i = 0; i < n; i++){
        temp *= 2;
        if(temp > m){
            std::cout << m << "\n";
            return 0;
        }
    }

    std::cout << (m % temp) << "\n";


    return 0;
}