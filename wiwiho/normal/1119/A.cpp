#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int c[n];
    for(int i = 0; i < n; i++){
        std::cin >> c[i];
    }

    int ans = 0;
    for(int i = n - 1; i > 0; i--){
        if(c[0] != c[i]){
            ans = i - 0;
            break;
        }
    }

    for(int i = 0; i < n - 1; i++){
        if(c[n - 1] != c[i]){
            if(n - 1 - i > ans){
                ans = n - 1 - i;
            }
            break;
        }
    }

    std::cout << ans << "\n";

    return 0;
}