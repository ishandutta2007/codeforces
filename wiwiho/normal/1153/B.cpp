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

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, h;
    std::cin >> n >> m >> h;

    int front[m];
    for(int i = 0; i < m; i++){
        std::cin >> front[i];
    }

    int left[n];
    for(int i = 0; i < n; i++){
        std::cin >> left[i];
    }

    int top[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> top[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j != 0){
                std::cout << " ";
            }
            int height = std::min(front[j], left[i]);
            std::cout << (top[i][j] ? height : 0);
        }
        std::cout << "\n";
    }

    return 0;
}