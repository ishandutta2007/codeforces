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

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    long long p[n];
    p[0] = 1;
    long long q[n];

    long long min = 1;

    for(int i = 0; i < n - 1; i++){
        std::cin >> q[i];
        p[i + 1] = p[i] + q[i];
        if(p[i + 1] < min){
            min = p[i + 1];
        }
    }

    min -= 1;
    std::vector<bool> book(n + 1);
    bool ans = true;
    for(int i = 0; i < n; i++){
        p[i] -= min;
        if(p[i] < 1 || p[i] > n || book[p[i]]){
            ans = false;
            break;
        }
        book[p[i]] = true;
    }

    if(!ans){
        std::cout << "-1\n";
    }
    else{
        for(int i = 0; i < n; i++){
            if(i != 0){
                std::cout << " ";
            }
            std::cout << p[i];
        }
        std::cout << "\n";
    }

    return 0;
}