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

bool put(std::vector<std::vector<int>>& map, int n, int i, int j){

    if(i >= n - 1 || j >= n - 1 || i <= 0 || j <= 0){
        return false;
    }

    if(map[i][j] == 0 && map[i + 1][j] == 0 && map[i - 1][j] == 0 && map[i][j + 1] == 0 && map[i][j - 1] == 0){
        map[i][j] = 1;
        map[i + 1][j] = 1;
        map[i - 1][j] = 1;
        map[i][j + 1] = 1;
        map[i][j - 1] = 1;
        return true;
    }

    return false;

}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> map(n, std::vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char temp;
            std::cin >> temp;
            if(temp == '#'){
                map[i][j] = 1;
            }
            else{
                map[i][j] = 0;
            }
        }
    }

    bool ans = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1){
                continue;
            }

            if(!(put(map, n, i, j) || put(map, n, i + 1, j) || put(map, n, i - 1, j) || put(map, n, i, j + 1) || put(map, n, i, j - 1))){
                ans = false;
                goto outside;
            }
        }
    }
    outside:

    std::cout << (ans ? "YES" : "NO") << "\n";

    return 0;
}