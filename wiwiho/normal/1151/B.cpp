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
#include <string.h>

//#define TEST

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> prototype(m);
    std::vector<std::vector<int>> c(n, prototype);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> c[i][j];
        }
    }

    int xxor = c[0][0];
    for(int i = 1; i < n; i++){
        xxor ^= c[i][0];
    }

    if(xxor > 0){
        std::cout << "TAK\n";
        for(int i = 0; i < n; i++){
            if(i != 0){
                std::cout << " ";
            }
            std::cout << 1;
        }
        std::cout << "\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if(c[i][j] != c[i][0]){
                std::cout << "TAK\n";
                for(int k = 0; k < n; k++){
                    if(k != 0){
                        std::cout << " ";
                    }
                    std::cout << (k == i ? j + 1 : 1);
                }
                std::cout << "\n";
                return 0;
            }
        }
    }

    std::cout << "NIE\n";

    return 0;
}