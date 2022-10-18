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

    std::string str;
    std::cin >> str;

    int f[10];
    bool replace[10];
    for(int i = 1; i < 10; i++){
        std::cin >> f[i];
        if(f[i] >= i){
            replace[i] = true;
        }
        else{
            replace[i] = false;
        }
    }

    bool start = false;
    for(int i = 0; i < n; i++){
        int num = str[i] - '0';
        if(replace[num]){
            if(num == f[num] && !start){
                continue;
            }
            start = true;
            str[i] = f[num] + '0';
        }
        else if(start){
            break;
        }
    }

    std::cout << str << "\n";

    return 0;
}