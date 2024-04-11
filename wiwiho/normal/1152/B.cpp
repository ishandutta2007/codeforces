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

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int x;
    std::cin >> x;

    std::vector<int> n;

    int t = 0;
    for(; t <= 40; ){

        if(t == 0){
            int i = 0;
            for(; (1 << i) <= x; i++);
            if((x ^ ((1 << i) - 1)) == 0){
                break;
            }
        }

        t++;

        if(t % 2 == 1){

            int i = 0;
            for(; (1 << i) <= x; i++);
            x ^= ((1 << i) - 1);
            n.push_back(i);

        }
        else{
            x += 1;
        }

        int i = 0;
        for(; (1 << i) <= x; i++);
        if((x ^ ((1 << i) - 1)) == 0){
            break;
        }

    }

    std::cout << t << "\n";

    for(int i = 0; i < n.size(); i++){
        if(i != 0){
            std::cout << " ";
        }
        std::cout << n[i];
    }
    std::cout << "\n";

    return 0;
}