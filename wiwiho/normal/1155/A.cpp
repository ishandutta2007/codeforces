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
    
    std::string str;
    std::cin >> str;

    char minc = 'z' + 1;
    int minp = -1;
    for(int i = str.size() - 1; i >= 0; i--){
        if(str[i] < minc){
            minc = str[i];
            minp = i;
        }
        if(str[i] > minc){
            std::cout << "YES\n";
            std::cout << (i + 1) << " " << (minp + 1) << "\n";
            return 0;
        }
    }
    
    std::cout << "NO\n";

    return 0;
}