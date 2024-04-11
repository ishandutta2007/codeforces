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
#include <typeinfo>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        if(!a[i]){
            break;
        }
        a.push_back(1);
    }

    int max = 0;
    int now = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i]){
            now++;
            max = std::max(max, now);
        }
        else{
            now = 0;
        }
    }

    std::cout << max << "\n";
    
    return 0;
}