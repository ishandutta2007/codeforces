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
#include <string>
#include <math.h>
#include <string.h>
#include <iomanip>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::set<int> a;
    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        a.insert(temp);
    }

    if(a.size() > 3){
        std::cout << "-1\n";
        return 0;
    }

    int x[a.size()];
    int k = 0;
    for(auto it = a.begin(); it != a.end(); it++){
        x[k] = *it;
        k++;
    }

    if(a.size() == 1){
        std::cout << "0\n";
        return 0;
    }
    if(a.size() == 2){
        if((x[0] + x[1]) % 2 == 1){
            std::cout << (x[1] - x[0]) << "\n";
            return 0;
        }
        std::cout << ((x[0] + x[1]) / 2 - x[0]) << "\n";
        return 0;
    }
    if(a.size() == 3){
        if((x[0] + x[2]) % 2 == 1){
            std::cout << "-1\n";
            return 0;
        }
        if((x[0] + x[2]) / 2 != x[1]){
            std::cout << "-1\n";
            return 0;
        }
        std::cout << (x[1] - x[0]) << "\n";
    }

    return 0;
}