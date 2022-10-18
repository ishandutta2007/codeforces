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

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int lastLeft;
    int lastRight;
    for(int i = 1; i <= n; i++){
        int temp;
        std::cin >> temp;
        if(temp){
            lastRight = i;
        }
        else{
            lastLeft = i;
        }
    }

    std::cout << std::min(lastLeft, lastRight) << "\n";

    return 0;
}