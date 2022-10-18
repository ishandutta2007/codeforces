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

    int n, m;
    std::cin >> n >> m;

    int chesteven = 0;
    int chestodd = 0;
    int keyeven = 0;
    int keyodd = 0;

    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        if(temp % 2 == 0){
            chesteven++;
        }
        else{
            chestodd++;
        }
    }

    for(int i = 0; i < m; i++){
        int temp;
        std::cin >> temp;
        if(temp % 2 == 0){
            keyeven++;
        }
        else{
            keyodd++;
        }
    }

    int ans = std::min(keyeven, chestodd) + std::min(keyodd, chesteven);
    std::cout << ans << "\n";

    return 0;
}