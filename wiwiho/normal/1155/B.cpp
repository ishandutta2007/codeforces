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

    int n;
    std::cin >> n;
    
    std::string number;
    std::cin >> number;

    int eight = 0;
    for(int i = 0; i < n - 10; i++){
        if(number[i] == '8'){
            eight++;
        }
    }

    if(eight > (n - 11) / 2){
        std::cout << "YES\n";
    }
    else{
        std::cout << "NO\n";
    }

    return 0;
}