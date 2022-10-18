#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

bool canPut(int n, int h, std::vector<int> bottle){
    std::sort(bottle.begin(), bottle.end(), std::greater<int>());

    for(int i = 0; i < n;){
        if(h >= bottle[i]){
            h -= bottle[i];
            i++;
            if(i < n){
                i++;
            }
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n,h;
    std::cin >> n >> h;

    std::vector<int> bottle(n);
    for(int i = 0; i < n; i++){
        std::cin >> bottle[i];
    }

    for(int i = n; i > 0; i--){
        std::vector<int> temp(bottle.begin(), bottle.begin() + i);
        if(canPut(i, h, temp)){
            std::cout << i << "\n";
            break;
        }
    }

    return 0;
}