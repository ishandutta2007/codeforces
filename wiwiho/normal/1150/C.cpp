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
    int one = 0;
    int two = 0;
    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        if(temp == 1){
            one++;
        }
        else{
            two++;
        }
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        if(one == 0 && two == 0){
            break;
        }
        if(i != 0){
            std::cout << " ";
        }

        if(sum == 0){
            if(two > 0){
                std::cout << 2;
                two--;
                sum += 2;
                continue;
            }
            std::cout << 1;
            one--;
            sum += 1;
            continue;
        }
        if(sum == 1){
            if(one > 0){
                std::cout << 1;
                one--;
                sum += 1;
                continue;
            }
            std::cout << 2;
            two--;
            sum += 2;
            continue;
        }

        if(sum % 2 == 1){
            if(two > 0){
                std::cout << 2;
                two--;
                sum += 2;
                continue;
            }
            std::cout << 1;
            one--;
            sum += 1;
            continue;
        }
        else{
            if(one > 0){
                std::cout << 1;
                one--;
                sum += 1;
                continue;
            }
            std::cout << 2;
            two--;
            sum += 2;
            continue;
        }

    }

    std::cout << "\n";

    return 0;
}