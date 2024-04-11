#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            std::cin >> temp;
            arr[i][j] ^= temp;
        }
    }

    bool ans = true;
    for(int i = 0; i < n; i++){
        int amount = 0;
        for(int j = 0; j < m; j++){
            if(arr[i][j]){
                amount++;
            }
        }
        if(amount % 2 != 0){
            ans = false;
            break;
        }
    }

    for(int i = 0; i < m && ans; i++){
        int amount = 0;
        for(int j = 0; j < n; j++){
            if(arr[j][i]){
                amount++;
            }
        }
        if(amount % 2 != 0){
            ans = false;
            break;
        }
    }

    std::cout << (ans ? "Yes" : "No") << "\n";

    return 0;
}